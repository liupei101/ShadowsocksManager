#include <iostream>
#include <cstring>
#include <cstdio>
#include "unity.h"
#include "portManager.h"

using namespace std;

int main()
{

    char cmd[BUFFER_SIZE], filename[BUFFER_SIZE];
    memset(filename, 0, sizeof(filename));
    memset(cmd, 0, sizeof(cmd));

    vector<string> arg;

    printWelcomeBanner();

    cin >> filename;
    getchar();

    portManager pm(filename);

    while(cin.getline(cmd, BUFFER_SIZE))
    {
        dispatchCmd(cmd, arg);
        if(arg[0] == CMD_EXIT)
        {
            break;
        }
        else if(arg[0] == CMD_CAT)
        {
            pm.catPortDetail(arg[1]);
        }
        else if(arg[0] == CMD_ADD)
        {
            pm.addPortDetail(arg[1], arg[2]);
        }
        else if(arg[0] == CMD_PWD)
        {
            pm.pwdPort(arg[1], arg[2]);
        }
        else if(arg[0] == CMD_DEL)
        {
            pm.delPort(arg[1]);
        }
        else
        {
            printInvalidBanner();
        }
    }

    restartSSServer(filename);

    return 0;
}
