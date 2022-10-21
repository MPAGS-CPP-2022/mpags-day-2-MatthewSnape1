#main cmake build script

#set cmake minimum requirments then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGScipher VERSION 0.1.0)
set(CMAKE_VERBOSE_MAKEFILE ON)

#set c++ standard directly

Set(CMAKE_CXX_STANDARD 14 )

#declare build of main mpags-cipher programme

add_executable(mpags-cipher 
    mpags-cipher.cpp 
    MPAGScipher/TransformChar.cpp
    MPAGScipher/ProcessCmdLne.cpp)

target_include_directories(mpags-cipher
   PRIVATE MPAGScipher)


#use standard set of flags

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher
     PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
      )