#include <stdio.h>
#include <socket.h>

DWORD WINAPI server::acceptProc(LPVOID lpParamter)
{
    /*server *p_server = (server *)lpParamter;
    sockaddr_in client_addr;
    int len = sizeof(client_addr);
    char msgBuff[256];
    int sk;
    while (1)
    {
        if ((sk = ::accept(p_server->sk(), (sockaddr*)&client_addr, &len) )== SOCKET_ERROR)
        {
            emit p_server->haveNewMsg(QObject::tr("accept 出错"));
            break;
        }
        
        sprintf(msgBuff, "新连接来自%s", inet_ntoa(client_addr.sin_addr));
        emit p_server->haveNewMsg(msgBuff);
        emit p_server->newClient(inet_ntoa(client_addr.sin_addr), sk);
    }*/

    server *p_server = (server *)lpParamter;
    int client[FD_SETSIZE];
    fd_set allset, rset;
    sockaddr_in client_addr;
    int len;
    int clientfd;
    int sockfd;

    int i;
    for (i=0; i<FD_SETSIZE; i++)
        client[i] = -1;
    FD_ZERO(&allset);
    int listenfd = p_server->sk();
    FD_SET(listenfd, &allset);

    int nready;
    int maxfd = listenfd;
    int maxi = -1;
    char buff[MAX_LEN+1];

    while (1)
    {
        rset = allset;
        nready = select(maxfd+1, &rset, NULL, NULL, NULL);
        if (FD_ISSET(listenfd, &rset)) //new connection
        {
            len = sizeof(client_addr);
            if ( (clientfd = ::accept(p_server->sk(), (sockaddr*)&client_addr, &len)) == SOCKET_ERROR)
            {
                emit p_server->haveNewMsg(QObject::tr("accept 出错"));
                break;
            }
            //找出client数组中第一个为-1的单元存放已经连接的socket
            for (i=0; i<FD_SETSIZE; i++)
            {
                if (client[i] <0)
                {
                    client[i] = clientfd;
                    break;
                }
            }
            if (i == FD_SETSIZE)
            {
                emit p_server->haveNewMsg(QObject::tr("error: too many clients!"));
                break;
            }
            //sprintf(buff, "新连接来自%s", inet_ntoa(client_addr.sin_addr));
            //emit p_server->haveNewMsg(buff);
            emit p_server->newClient(inet_ntoa(client_addr.sin_addr), clientfd);
            FD_SET(clientfd, &allset);
            if (clientfd > maxfd)
                maxfd = clientfd;
            if (i>maxi)
                maxi = i;
            if (--nready <= 0)
                continue;
        }
        for (i=0; i<=maxi; i++)
        {
            if ( (sockfd = client[i]) < 0)
                continue;
            if (FD_ISSET(sockfd, &rset))
            {
                int n;
                //客户端已经关闭连接
                if ( (n = recv(sockfd, buff, MAX_LEN, 0 )) <= 0)
                {
                    closesocket(sockfd);
                    FD_CLR(sockfd, &allset);
                    client[i] = -1;
                    emit p_server->haveNewMsg(QObject::tr("client closed"));
                    emit p_server->sClientClose(sockfd);
                }
                else //收到数据
                {
                    buff[n] = 0;
                    emit p_server->haveNewMsg( buff, sockfd);
                    if (--nready <= 0)
                        break;
                }
            }
        } //for (i=0; i<=maxi; i++)
    }
    return 0;
}


int main(int argc, char const *argv[])
{
	 WORD wVersionRequested;
    WSADATA wsaData;
    wVersionRequested=MAKEWORD(2,2);
    if(WSAStartup(wVersionRequested,&wsaData)!=0)
    {
        //Winsock初始化错误
        msgBox.exec();
        return;
    }
    if(wsaData.wVersion!=wVersionRequested)
    {
        //Winsock版本不匹配        
        WSACleanup();
        return;
    }

    if ((m_sk = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR)
    {        
        WSACleanup();
        return;
    }
    bool ok;
    unsigned short port = ui.portLineEdit->text().toInt(&ok, 10);
    if (ok == false)
    {
        //端口输入错误
        closesocket(m_sk);
        m_sk = -1;
        WSACleanup();
        return;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET; //使用互联网际协议，即IP协议
    addr.sin_port = htons(port);
    addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

    if (bind(m_sk, (sockaddr *)&addr, sizeof(addr)) == SOCKET_ERROR)
    {
        //绑定端口失败

        closesocket(m_sk);
        m_sk = -1;
        WSACleanup();
        return;
    }

    if (listen(m_sk, 10) == SOCKET_ERROR)
    {
        //监听端口失败
        closesocket(m_sk);
        m_sk = -1;
        WSACleanup();
        return;
    }
    updateMsgRecs(tr("等待连接..."));
    //创建线程去等待连接
    HANDLE h = CreateThread(NULL, 0, &server::acceptProc, (LPVOID)this, 0, 0);
    if (h == NULL)
    {        
        closesocket(m_sk);
        m_sk = -1;
        WSACleanup();
        return;        
    }
    CloseHandle(h);
	/* code */
	return 0;
}