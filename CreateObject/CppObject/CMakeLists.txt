#---------------------------------------------------
# CreateObjCMake - building C++ with CMake
#   - setup VS Code for debugging
#---------------------------------------------------

#---------------------------------------------------
project(CreateObj)
#---------------------------------------------------
set(CMake_CXX_STANDARD 20)
#---------------------------------------------------
# build CreateObj.exe in folder build/debug
#---------------------------------------------------
add_executable(CreateObj CreateObj.cpp)

