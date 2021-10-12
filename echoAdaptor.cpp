//
// Created by devin on 21-10-12.
//

#include "echoAdaptor.h"
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <limits.h>

int32_t echoAdaptor::Random() {
    return rand();
}

std::string echoAdaptor::Hello(const std::string &name) {
    return  "Hello " + name + "!";
}

DBus::Variant echoAdaptor::Echo(const ::DBus::Variant &input) {
    this->Echoed(input);
    return input;
}

std::vector<uint8_t> echoAdaptor::Cat(const std::string &file) {
    FILE *handle = fopen(file.c_str(), "rb");
    if (!handle) throw DBus::Error("org.freedesktop.DBus.EchoDemo.ErrorFileNotFound", "file not found");
    uint8_t buff[1024];
    size_t ret = fread(buff, 1, sizeof(buff), handle);
    fclose(handle);
    return std::vector< uint8_t > (buff, buff + ret);
}
int32_t echoAdaptor::Sum(const std::vector<int32_t> &ints) {
    int32_t sum=0;
    for (auto lin : ints) {
        sum+=lin;
    }
    return sum;
}

std::map<std::string, std::string> echoAdaptor::Info() {
    std::map< std::string, std::string > info;
    char hostname[HOST_NAME_MAX];

    gethostname(hostname, sizeof(hostname));
    info["hostname"] = hostname;
    info["username"] = getlogin();
    return info;
}
echoAdaptor::echoAdaptor(DBus::Connection &connection): DBus::ObjectAdaptor(connection, ECHO_SERVER_PATH)
{

}
