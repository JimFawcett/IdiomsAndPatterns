// test1.cpp

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