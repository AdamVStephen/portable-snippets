cmake_minimum_required(VERSION 3.1)
project(maxage)

# Ensure Debug build
set(CMAKE_BUILD_TYPE Debug)

# Force C++11
set(CMAKE_CXX_STANDARD 11)

add_executable(maxage maxage.cpp)
