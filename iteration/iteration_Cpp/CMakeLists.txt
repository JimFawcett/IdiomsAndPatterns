#---------------------------------------------------
# Iteration CMake - building C++ with CMake
#   - setup VS Code for debugging
#---------------------------------------------------

#---------------------------------------------------
project(Iteration)
#---------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
#---------------------------------------------------
# build Iteration.exe in folder build/debug
#---------------------------------------------------
add_executable(Iteration Iteration.cpp)

