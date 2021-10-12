//
// Created by devin on 21-10-12.
//

#ifndef DBUSDEMO_ECHOADAPTOR_H
#define DBUSDEMO_ECHOADAPTOR_H

#include "adaptor.h"

static const char *ECHO_SERVER_NAME = "org.freedesktop.DBus.Examples.Echo";
static const char *ECHO_SERVER_PATH = "/org/freedesktop/DBus/Examples/Echo";


class echoAdaptor
        :public org::freedesktop::DBus::EchoDemo_adaptor,
        public DBus::IntrospectableAdaptor,
        public DBus::ObjectAdaptor{
public:
    int32_t Random() override;

    std::string Hello(const std::string &name) override;

    DBus::Variant Echo(const ::DBus::Variant &input) override;

    std::vector<uint8_t> Cat(const std::string &file) override;

    int32_t Sum(const std::vector<int32_t> &ints) override;

    std::map<std::string, std::string> Info() override;
    echoAdaptor(DBus::Connection &connection);
};


#endif //DBUSDEMO_ECHOADAPTOR_H
