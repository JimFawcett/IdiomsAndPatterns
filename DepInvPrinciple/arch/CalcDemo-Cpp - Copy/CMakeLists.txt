#---------------------------------------------------
# DataOpsCMake - building C++ with CMake
#   - setup VS Code for debugging
#---------------------------------------------------

#---------------------------------------------------
project(GenericDIP)
#---------------------------------------------------
set(CMake_CXX_STANDARD 20)
#---------------------------------------------------
# build CreateObj.exe in folder build/debug
#---------------------------------------------------
add_executable(GenericDIP GenericDIP.cpp)

