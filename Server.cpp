//
// Created by devin on 21-10-12.
//
#include "echoAdaptor.h"

DBus::BusDispatcher dispatcher;

void niam(int sig)
{
    dispatcher.leave();
}


int main(int argc,char *argv[]){
    DBus::default_dispatcher = &dispatcher;

    DBus::Connection conn = DBus::Connection::SessionBus();
    conn.request_name(ECHO_SERVER_NAME);

    echoAdaptor server(conn);

    dispatcher.enter();
}