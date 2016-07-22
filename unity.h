#ifndef UNITY_H_INCLUDED
#define UNITY_H_INCLUDED
#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#define BUFFER_SIZE 1024
#define STR_SIZE 100
#define ARG_NUM 3
using namespace std;

const string PATTERN = " ";
const string CMD_EXIT = "EXIT";
const string CMD_CAT = "CAT";
const string CMD_ADD = "ADD";
const string CMD_DEL = "DEL";
const string CMD_PWD = "PWD";

void printWelcomeBanner()
{
    cout << "--------- ShadowSocks Manager is Running! ---------" << "\n";
    cout << "Please input file path you manager: ";
}

void printInvalidBanner()
{
    cout << "Invalid cmd!" << "\n";
}

void dispatchCmd(string cmd, vector<string>& arg)
{
    arg.clear();
    cmd += PATTERN;
    int sz = (int)cmd.size();
    for(int i = 0;i < sz;i ++)
    {
        int pos = cmd.find(PATTERN, i);
        if(pos < sz)
        {
            arg.push_back(cmd.substr(i, pos - i));
            i = pos + PATTERN.size() - 1;
        }
    }

    arg.resize(ARG_NUM);
    /*
    for(int i = 0;i < arg.size();i ++)
    {
        cout << "arg " << i << " : " << arg[i] << "*\n";
    }
    */
}

void restartSSServer(const string& filename)
{
    string stopCmd  = "ssserver -c " + filename + " -d stop";
    string startCmd = "ssserver -c " + filename + " -d start";
    system(stopCmd.c_str());
    sleep(5);
    system(startCmd.c_str());
}

#endif // UNITY_H_INCLUDED

