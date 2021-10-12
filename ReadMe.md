
### session bus dmeo

#### install libdbus-c++-1 
```shell
sudo apt-get install libdbus-c++-dev
```

#### generating code for interface org.freedesktop.DBus.EchoDemo
```shell
dbusxx-xml2cpp echo-introspect.xml --proxy=proxy.h --adaptor=adaptor.h
```
#### client interview from proxy.h 
```c++
class echoClient
        :public org::freedesktop::DBus::EchoDemo_proxy,
public DBus::IntrospectableProxy,
public DBus::ObjectProxy{
public:
    echoClient(DBus::Connection &conn, const DBus::Path &path, const char *service);

    void Echoed(const ::DBus::Variant &value) override;
};
```
#### client interview from adaptor.h
```c++
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
```
#### Cmake rule
```shell
cmake_minimum_required(VERSION 3.14)
project(dbusDemo)

include(FindPkgConfig)
pkg_check_modules(PKGS REQUIRED dbus-c++-1)
message("pkg cflags: ${PKGS_CFLAGS}")
message ("pkg include dirs: ${PKGS_INCLUDE_DIRS}")
include_directories(${PKGS_INCLUDE_DIRS})
link_directories(${PKGS_LIBRARY_DIRS})

add_executable(dbusClient Client.cpp echoClient.cpp echoClient.h proxy.h)
add_executable(dbusServer Server.cpp echoAdaptor.cpp adaptor.h echoAdaptor.h)
target_link_libraries(dbusServer ${PKGS_LDFLAGS})
target_link_libraries(dbusClient ${PKGS_LDFLAGS})
```

#### build
```shell
cd dbusDemo
dbusxx-xml2cpp echo-introspect.xml --proxy=proxy.h --adaptor=adaptor.h
mkdir build
cd build
cmake ../
make -j8
```
### How to test
#### generating env
```shell
dbus-launch --sh-syntax --exit-with-session >> env.sh
```
#### execute program
##### server
```shell
source ./env.sh
./dbusServer
```
##### client
```shell
source ./env.sh
./dbusClient
846930886
Hello Hello!
Caught error: org.freedesktop.DBus.EchoDemo.ErrorFileNotFound
	file not found
```
