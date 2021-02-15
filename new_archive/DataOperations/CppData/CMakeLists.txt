#---------------------------------------------------
# DataOpsCMake - building C++ with CMake
#   - setup VS Code for debugging
#---------------------------------------------------

#---------------------------------------------------
project(DataOps)
#---------------------------------------------------
set(CMake_CXX_STANDARD 20)
#---------------------------------------------------
# build CreateObj.exe in folder build/debug
#---------------------------------------------------
add_executable(DataOps DataOps.cpp)

