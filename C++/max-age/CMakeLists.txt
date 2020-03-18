cmake_minimum_required(VERSION 3.0.0)
project(maxage)

# Dependent on headers from sdn1.2
include_directories(/work/astephen/git-wd/BUILD.0023/marte1_cmake/Tools/sdn1.2/include/)

# Ensure Debug build
set(CMAKE_BUILD_TYPE Debug)

add_executable(maxage maxage.cpp)
