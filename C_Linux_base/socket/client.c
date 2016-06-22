#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char ch = 'A';
    
    //创建套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("219.223.242.244");
    address.sin_port = htons(12345);
    len = sizeof(address);
    
    //将创建的套接字连接到服务器套接字
    result = connect(sockfd, (struct sockaddr *)&addresss, len);
    if(result==-1)
    {
        perror("oops: client1");
        exit(1);
    }
    
    write(sockfd, &ch, 1);
    read(sockfd, &ch, 1);
    printf("char from server = c%\n",ch);
    close(sockfd);
    exit(0);
}