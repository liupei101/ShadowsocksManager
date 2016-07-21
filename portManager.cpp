#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "portManager.h"
using namespace std;

const char* FILE_PATH = "/etc/ss.json";
const int LEN = 1024;
typedef Json::Value::Members JsonValMem;
typedef Json::Value::Members::iterator JsonValMemIt;
typedef Json::Value JsonVal;

portManager::portManager(const char* filename)
{
    memset(filePath, 0, LEN);
    memcpy(filePath, filename, LEN);
    if(strlen(filePath) == 0)
    {
        memcpy(filePath, FILE_PATH, sizeof(FILE_PATH));
    }

    string buff, line;
    ifstream f(filePath);
    if(!f.is_open())
    {
        cout << "file " << filePath << " open failed!\n";
        exit(-1);
        return ;
    }
    while(getline(f, line)) buff += line;

    if(!reader.parse(buff, root))
    {
        cout << "Json parse failed!" << endl;
    }
    f.close();
}

portManager::~portManager()
{
    string buff = root.toStyledString();
    ofstream f(filePath);
    f << buff;
}

void portManager::catPortDetail(const string& arg)
{
    JsonVal portDetail = root["port_password"];
    if(arg.size() == 0)
    {
        JsonValMem portNum = portDetail.getMemberNames();
        for(JsonValMemIt it = portNum.begin();it != portNum.end();it ++)
        {
            string name = (*it);
            cout << ">>> " << name << "\t" << portDetail[name].asString() << endl;
        }
    }
    else
    {
        bool flag = false;
        Json::Value::Members portNum = portDetail.getMemberNames();
        for(JsonValMemIt it = portNum.begin();it != portNum.end();it ++)
        {
            string name = (*it);
            if(name == arg)
            {
                cout << ">>> " << name << "\t" << portDetail[name].asString() << endl;
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            cout << "Can not find details about port " << arg << "\n";
        }
    }
}

void portManager::addPortDetail(const string& portNum, const string& password)
{
    if(root["port_password"][portNum].empty())
    {
        root["port_password"][portNum] = password;
    }
    else
    {
        cout << "Add port error, The port " << portNum << " has been used!\n";
    }
}

void portManager::pwdPort(const string& portNum, const string& newPassword)
{
    if(!root["port_password"][portNum].empty())
    {
        root["port_password"][portNum] = newPassword;
    }
    else
    {
        cout << "Modify password error, The port " << portNum << " has not been used!\n";
    }
}

void portManager::delPort(const string& portNum)
{
    if(!root["port_password"][portNum].empty())
    {
        root["port_password"].removeMember(portNum);
    }
    else
    {
        cout << "Delete port error, The port " << portNum << " does not exist!\n";
    }
}

