#include <cstdio>
#include"ServerFuc.h"
int main()
{
    ServerFuc sf("server.json");
    sf.startServer();
    return 0;
}