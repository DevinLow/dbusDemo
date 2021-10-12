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