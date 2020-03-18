cmake_minimum_required(VERSION 3.1)
project(maxage)

# TODO: create a github acceptable version of sdn header file.
# In the meantime...
# Dependent on headers from sdn1.2
include_directories(/work/astephen/git-wd/BUILD.0023/marte1_cmake/Tools/sdn1.2/include/)
# sdn1.2 may be installed in multiple locations
include_directories(/work/astephen/Marte1_Cmake/marte1_cmake/Tools/sdn1.2/include/)

# Ensure Debug build
set(CMAKE_BUILD_TYPE Debug)

# Force C++11
set(CMAKE_CXX_STANDARD 11)

add_executable(maxage maxage.cpp)
