#ifndef USERMANAGER_H_INCLUDED
#define USERMANAGER_H_INCLUDED
#include "json/json.h"
using std::string;
const int STR_LEN = 1024;

class portManager
{

public:
    portManager(const char* filename);

    ~portManager();

    void catPortDetail(const string& arg);

    void addPortDetail(const string& portNum, const string& password);

    void pwdPort(const string& portNum, const string& newPassword);

    void delPort(const string& portNum);

    void prvPort(const string& portNum, const string& newPrv);

private:
    char filePath[STR_LEN];
    Json::Reader reader;
    Json::Value root;
};

#endif // USERMANAGER_H_INCLUDED
