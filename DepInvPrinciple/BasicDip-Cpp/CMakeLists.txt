#---------------------------------------------------
# DataOpsCMake - building C++ with CMake
#   - setup VS Code for debugging
#---------------------------------------------------

#---------------------------------------------------
project(BasicDIP)
#---------------------------------------------------
set(CMake_CXX_STANDARD 20)
#---------------------------------------------------
# build CreateObj.exe in folder build/debug
#---------------------------------------------------
add_executable(BasicDIP BasicDIP.cpp)

