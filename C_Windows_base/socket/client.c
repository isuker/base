#include <socket.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    WORD wVersionRequested;
       WSADATA wsaData;
       wVersionRequested=MAKEWORD(2,2);
       if(WSAStartup(wVersionRequested,&wsaData)!=0)
       {
           //Winsock初始化错误
           QMessageBox msgBox(QMessageBox::Warning, tr("错误"), tr("Winsock初始化错误"), QMessageBox::Ok, 0);
           msgBox.exec();
           return;
       }
       if(wsaData.wVersion!=wVersionRequested)
       {
           //Winsock版本不匹配
           QMessageBox msgBox(QMessageBox::Warning, tr("错误"), tr("Winsock版本不匹配"), QMessageBox::Ok, 0);
           msgBox.exec();
           WSACleanup();
           return;
       }

       if ((m_sk = socket(AF_INET, SOCK_STREAM, 0)) == SOCKET_ERROR)
       {
           QMessageBox msgBox(QMessageBox::Warning, tr("错误"), tr("创建socket失败"), QMessageBox::Ok, 0);
           msgBox.exec();
           WSACleanup();
           return;
       }

       sockaddr_in addr;
       addr.sin_family = AF_INET;

       bool ok;
       unsigned short port = ui.portLineEdit->text().toInt(&ok, 10);
       if (ok == false)
       {
           QMessageBox msgBox(QMessageBox::Warning, tr("错误"), tr("端口输入错误"), QMessageBox::Ok, 0);
           msgBox.exec();
           closesocket(m_sk);
           m_sk = -1;
           WSACleanup();
           return;
       }
       addr.sin_port  = htons(port);
       addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

       if (0 == ::connect(m_sk, (sockaddr *)&addr, sizeof(addr)))
       {
           updateMsgRecs(tr("连接成功..."));
           HANDLE h = CreateThread(NULL, 0, &client::recvProc, (LPVOID)this, 0, 0);
           CloseHandle(h);
       }
       else
       {
           QMessageBox msgBox(QMessageBox::Warning, tr("错误"), tr("连接出错"), QMessageBox::Ok, 0);
           msgBox.exec();
           closesocket(m_sk);
           m_sk = -1;
           WSACleanup();
           
       }
	/* code */
	return 0;
}