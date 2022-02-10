cmake_minimum_required(VERSION 3.21)
project(IPK_proj1cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(IPK_proj1cpp  main.cpp Tcp.cpp Tcp.h HttpRequest.cpp HttpRequest.h HTTPResponse.cpp HTTPResponse.h Server.cpp Server.h Controller.cpp Controller.h ServerInfo.cpp ServerInfo.h)
