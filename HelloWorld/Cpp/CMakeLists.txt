#---------------------------------------------------
# HelloPrjCMake - building C++ with CMake
#   - setup VS Code for debugging
#---------------------------------------------------

#---------------------------------------------------
project(HelloPrj)
#---------------------------------------------------
set(CMake_CXX_STANDARD 20)
#---------------------------------------------------
# build HelloCMake.obj in folder build/HelloCMake.dir/debug
#---------------------------------------------------
add_executable(HelloPrj Hello.cpp)

