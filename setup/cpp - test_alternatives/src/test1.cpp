/////////////////////////////////////////////////////////////
// test1.cpp - demonstrate creating basic project          //
//                                                         //
// Jim Fawcett, https://JimFawcett.github.io, 15 Dec 2020  //
/////////////////////////////////////////////////////////////
/*
    Create basic project:
    - mkdir cpp
    - echo " " > test1.cpp
    - open editor and add content
    - echo " " > CMakeLists.txt
    - add content, using CMakeDemo as reference
    - mkdir build
    Build project:
    - cd build
    - cmake ..
    - cmake --build .
    Run image:
    - "./debug/test1"
    Clean project:
    - delete contents of build directory
*/

#include <iostream>
#include <string>

auto helper() -> std::string {
    auto s = "hello from helper";
    return s;
}
void flush_test() {
    std::cout.flush();
}

int main() {
    std::cout << "\n  hello test1";
    //flush_test();
    std::cout << " " << helper();
    //flush_test();
    std::cout << "\n\n  That's all Folks\n\n";
}