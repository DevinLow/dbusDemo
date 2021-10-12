//
// Created by devin on 21-10-13.
//

#ifndef DBUSDEMO_ECHOCLIENT_H
#define DBUSDEMO_ECHOCLIENT_H

#include "proxy.h"

static const char *ECHO_SERVER_NAME = "org.freedesktop.DBus.Examples.Echo";
static const char *ECHO_SERVER_PATH = "/org/freedesktop/DBus/Examples/Echo";
class echoClient
        :public org::freedesktop::DBus::EchoDemo_proxy,
public DBus::IntrospectableProxy,
public DBus::ObjectProxy{
public:
    echoClient(DBus::Connection &conn, const DBus::Path &path, const char *service);

    void Echoed(const ::DBus::Variant &value) override;
};


#endif //DBUSDEMO_ECHOCLIENT_H
