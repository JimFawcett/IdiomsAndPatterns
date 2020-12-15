#---------------------------------------------------
# DemoDateTime - demonstrate C++ timer class
#---------------------------------------------------
#
#---------------------------------------------------
# Build directions:
# 1. navigate to project directory
# 2. mkdir build
# 3. cmake ..
# 4. cmake --build . [--config Debug] | [--config Release]
# To Execute:
# 5. "./debug/DemoDateTime"
#---------------------------------------------------

project(DemoDateTime)

set(CMake_CXX_STANDARD 20)

#---------------------------------------------------
# build DemoDateTime.exe in folder build/Debug
#---------------------------------------------------
#add_compile_definitions(TEST_DATETIME)
add_executable(DemoDateTime src/DateTime.cpp)
add_executable(DemoDateTime src/DemoDateTime.cpp)

#---------------------------------------------------
# For a demo of CMake syntax see
# https://github.com/JimFawcett/CppBasicDemos/tree/master/CMakeDemo
#---------------------------------------------------
