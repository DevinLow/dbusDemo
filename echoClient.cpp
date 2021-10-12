//
// Created by devin on 21-10-13.
//

#include "echoClient.h"
#include <iostream>

void echoClient::Echoed(const ::DBus::Variant &value) {
    std::cout << "!";
}

echoClient::echoClient(DBus::Connection &conn, const DBus::Path &path, const char *service) : ObjectProxy(conn, path,
                                                                                                          service) {

}
