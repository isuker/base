#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int server_sockfd, client_sockfd;
    int server_len, clinet_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(9734);
    server_len = sizeof(server_address);
    
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
    
    //创建一个连接队列，忽略子进程的退出细节，等待客户的到来
    listen(server_sockfd, 5);    
    
    signal(SIGCHLD, SIG_IGN);
    
    while(1)
    {
        char ch;
        printf("server waiting\n");
        
        //接受连接
        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_len);
        
        //通过fork调用为这个客户创建一个子进程，然后测试你是在父进程中还是子进程中
        if(fork()==0)    //如果在子进程中，就可以对client_sockfd的客户进程读写操作
        {
            read(client_sockfd, &ch, 1);
            sleep(5);    //仅为了演示
            ch++;
            write(client_sockfd, &ch, 1);
            close(client_sockfd);
            exit(0);
        }
        else            //在父进程中，需要关闭这个客户
            close(client_sockfd);
    }
}