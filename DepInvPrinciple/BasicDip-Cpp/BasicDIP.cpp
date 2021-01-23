/////////////////////////////////////////////////
// BasicDIP.cpp                                //
//                                             //
// Jim Fawcett, 23 Jan 2021                    //
/////////////////////////////////////////////////
/*
    Demonstrates Dependency Inversion Principle:
      "High level modules should not depend on
       low level modules.  Both should depend
       on abstractions."

    This demonstration builds a basic demo with
    self-annunciating low level components.
    
      - High level part: Demo<T>
      - Low level parts: First, Second
      - Abstraction defined in this package: 
        - trait Say
    The definitons of First and Second could be
    changed in any way that is compatible with 
    trait Say without affecting compilation of
    Demo<T>.
*/
#include <iostream>
using Byte = unsigned short;

struct Say {
    static Say create();
    void set_id(Byte id);
    void say();
};

class First : public Say {
public:
    First() : id_(0) {}
    Say create() {
        return First();
    }
    void set_id(Byte id)
    {
        id_ = id;
    }
    void say() {
        std::cout << "\n  First here with id = " << id_;
    }
private: 
    Byte id_;
};

class Second : public Say {
public:
    Second() : id_(0) {}
    Say create() {
        return Second();
    }
    void set_id(Byte id)
    {
        id_ = id;
    }
    void say() {
        std::cout << "\n  Second here with id = " << id_;
    }
private: 
    Byte id_;
};

template<typename T>
class Demo {
public:
    void set_id(Byte id) {
        my_say.set_id(id);
    }
    Byte get_id() {
        return my_say.get_id();
    }
    void say_it() {
        my_say.say();
    }
private:
    T my_say;
};
int main() {
    std::cout << "\n  -- basic_dip demo --\n";

    Demo<First> demo1;
    demo1.set_id(1);
    demo1.say_it();

    Demo<Second> demo2;
    demo2.set_id(2);
    demo2.say_it();

    std::cout << "\n  That's all Folks!\n\n";
}