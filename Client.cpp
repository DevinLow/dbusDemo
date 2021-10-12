//
// Created by devin on 21-10-13.
//

#include "echoClient.h"

DBus::BusDispatcher dispatcher;

int main()
{
    DBus::default_dispatcher = &dispatcher;

    DBus::Connection conn = DBus::Connection::SessionBus();

    echoClient client(conn, ECHO_SERVER_PATH, ECHO_SERVER_NAME);

    std::cout << client.Random() << std::endl;
    std::cout << client.Hello("Hello") << std::endl;
    try
    {
        client.Cat("foobar");
    }
    catch(DBus::Error &e)
    {
        std::cout << "Caught error: " << e.name() << std::endl
             << "\t" << e.message() << std::endl;
    }
    client.Cat("/etc/hosts");

    return 0;
}