#include "TcpSocket.h"
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/fcntl.h>
#include<sys/socket.h>
#include<errno.h>
#include<arpa/inet.h>
int TcpSocket::setNonBlock(int fd)
{
    int flag = fcntl(m_socket, F_GETFL);
    if (flag == -1)
    {
        return flag;
    }
    flag |= O_NONBLOCK;
   int ret = fcntl(m_socket, F_SETFL, flag);
   return ret;
}
int TcpSocket::setBlock(int fd)
{
    int flag = fcntl(m_socket, F_GETFL);
    if (flag == -1)
    {
        return flag;
    }
    flag &= ~O_NONBLOCK;
    int ret = fcntl(m_socket, F_SETFL, flag);
    return ret;
}
//成功返回0
//失败返回-1 设置ETIMEOUT
int TcpSocket::readTimeout(unsigned int wait_time)
{
    int ret = 0;
    if (wait_time > 0)
    {
        fd_set read_set;
        FD_ZERO(&read_set);
        FD_SET(m_socket, &read_set);
        struct timeval timeout;
        timeout.tv_sec = wait_time;
        timeout.tv_usec = 0;
        do
        {
             ret = select(m_socket+1, &read_set, NULL, NULL, &timeout);
             

        } while (ret < 0 && errno == EINTR);
        if (ret == 0)
        {
            ret = -1;
            errno = ETIMEDOUT;
        }
        else if (ret == 1)
        {
            ret = 0;
        }
    }

    return ret;
}
int TcpSocket::writeTimeout(unsigned int wait_time)
{
    int ret = 0;
    if (wait_time > 0)
    {
        fd_set write_set;
        FD_ZERO(&write_set);
        FD_SET(m_socket, &write_set);
        struct timeval timeout;
        timeout.tv_sec = wait_time;
        timeout.tv_usec = 0;
        do
        {
            ret = select(m_socket+1, NULL, &write_set, NULL, &timeout);
        } while (ret < 0 && errno == EINTR);
        if (ret == 0)
        {
            ret = -1;
            errno = ETIMEDOUT;
        }
        else if (ret == 1)
        {
            ret = 0;
           
        }
    }
    return ret;
    
}
int TcpSocket::connectTimeout(sockaddr_in* addr, unsigned int wait_time)
{
    if (wait_time > 0)
    {
        setNonBlock(m_socket);
    }
    int ret =connect(m_socket, (struct sockaddr*)addr, sizeof(addr));
    if (ret < 0 && errno == EINPROGRESS)
    {
        fd_set write_set;
        FD_ZERO(&write_set);
        FD_SET(m_socket, &write_set);
        struct timeval timeout;
        timeout.tv_sec = wait_time;
        timeout.tv_usec = 0;
        do 
        {
            int ret = select(m_socket+1, NULL, &write_set, NULL, &timeout);
        } 
        while (ret < 0 && errno == EINTR);
        if (ret ==0)
        {
            ret = -1;
            errno = ETIMEDOUT;
        }
        else if (ret == -1)
        {
            return -1;
        }
        else if (ret == 1)
        {
            int err;
            socklen_t len = sizeof(err);
            int sockret =getsockopt(m_socket, SOL_SOCKET, SO_ERROR, &err, &len);
            if (sockret == -1)
            {
                return -1;
            }
            else if (err == 0)
            {
                ret = 0;
            }
            else
            {
                errno = err;
                ret = -1;
            }
        }
        
       
    }
    if (wait_time > 0)
    {
        setBlock(m_socket);
    }
    return ret;
    
}
int TcpSocket::readn(void* buf, int count)
{
    size_t nleft = count;
    char* rbuf = (char*)buf;
    while (nleft > 0) 
    {
        size_t nread = read(m_socket, rbuf, nleft);
        if (nread < 0)
        {
            if (errno == EINTR)
            {
                continue;
            }
            return -1;
        }
        else if (nread == 0)
        {
            return count - nleft;
        }

        rbuf += nread;
        nleft -= nread;
    }
    return count;
    
   
    
}

int TcpSocket::writen(const void* buf, int count)
{
    char* wbuf = (char*)buf;
    size_t nleft = count;
    while (nleft>0)
    {
        size_t nwrite = write(m_socket, wbuf, nleft);
        if (nwrite < 0)
        {
            if (errno == EINTR)
            {
                continue;
            }
            return -1;
        }
        else if (nwrite == 0)
        {
            return count - nleft;
        }

        wbuf += nwrite;
        nleft -= nwrite;
    }
    return count;
}

TcpSocket::TcpSocket()
{

}

TcpSocket::TcpSocket(int socket)
{
    m_socket = socket;
}

TcpSocket::~TcpSocket()
{
}

int TcpSocket::connectToHost(string ip, unsigned short port, int timeout)
{
    int ret = 0;
    if (port <= 0 || port > 65535 || timeout < 0)
    {
        ret = ParamError;
        return ret;
    }
    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (m_socket < 0)
    {
        ret = errno;
        return ret;
    }
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip.data());
    addr.sin_port = htons(port);

    ret = connectTimeout((struct sockaddr_in*)&addr, (unsigned int)timeout);
    if (ret < 0)
    {
        if (ret == -1 && errno == ETIMEDOUT)
        {
            ret = TimeoutError;
            return ret;
        }
        else
        {
            printf("connectTimeOut异常 : %d\n", errno);
            
            return errno;
        }
    }
    return ret;
}
//0未超时
int TcpSocket::sendMessage(string data, int timeout)
{
    int ret = writeTimeout(timeout);
    if (ret == 0)
    {
        //设置数据头为4字节
        size_t datalen = data.size()+4;
        unsigned char* ndata = (unsigned char*)malloc(datalen);
        if (ndata == NULL)
        {
            ret = MallocError;
            printf("MallocError\n");
            return ret;
        }
        int netlen = htonl(data.size());
        memcpy(ndata, &netlen, 4);
        memcpy(ndata + 4, data.data(), data.size());

        int wret = writen( ndata, datalen);
        if (wret < datalen)//send failed
        {
            if (ndata != NULL)
            {
                free(ndata);
                ndata = NULL;
            }
            return wret;
        }
        if (ndata != NULL)
        {
            free(ndata);
            ndata = NULL;
        }     

    }
    else
    {
        if (ret == -1 && errno == ETIMEDOUT)
        {
            ret = TimeoutError;
            cout << "TimeoutError" << endl;
        }
    }
    return ret;
}

string TcpSocket::recvMessage(int timeout)
{
    int ret = readTimeout(timeout);
    if (ret != 0)
    {
        if (ret == -1 || errno == ETIMEDOUT)
        {
            printf("readTimeout(timeout) err: TimeoutError \n");
            return string();
        }
        else
        {
            printf("readTimeout(timeout) err: %d \n", ret);
            return string();
        }
    }

    int netdatalen = 0;
    ret = readn(&netdatalen, 4); //读包头 4个字节
    if (ret == -1)
    {
        printf("func readn() err:%d \n", ret);
        return string();
    }
    else if (ret < 4)
    {
        printf("func readn() err peer closed:%d \n", ret);
        return string();
    }

    int n = ntohl(netdatalen);
    // 根据包头中记录的数据大小申请内存, 接收数据
    char* tmpBuf = (char*)malloc(n + 1);
    if (tmpBuf == NULL)
    {
        ret = MallocError;
        printf("malloc() err \n");
        return NULL;
    }

    ret = readn(tmpBuf, n); //根据长度读数据
    if (ret == -1)
    {
        printf("func readn() err:%d \n", ret);
        return string();
    }
    else if (ret < n)
    {
        printf("func readn() err peer closed:%d \n", ret);
        return string();
    }

    tmpBuf[n] = '\0'; //多分配一个字节内容，兼容可见字符串 字符串的真实长度仍然为n
   string sret = string(tmpBuf);
   string data = sret;
    // 释放内存
    free(tmpBuf);

    return data;


}

void TcpSocket::disConnect()
{
    if (m_socket >= 0)
    {
        close(m_socket);
    }
}

