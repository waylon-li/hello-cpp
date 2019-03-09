cmake_minimum_required(VERSION 2.12)

#set(CMAKE_INCLUDE_PATH "/usr/include")
#set(CMAKE_LIBRARY_PATH "/usr/lib")
project(cgi_checkbox)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
SET(CMAKE_BUILD_TYPE Debug)
	
add_executable(cgi_checkbox cgi_checkbox.cpp)
include_directories("/usr/include") #添加动态连接库的路径
link_directories("/usr/lib") #添加动态连接库的路径
target_link_libraries(cgi_checkbox -lcgicc)
