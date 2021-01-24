/////////////////////////////////////////////////
// GenericDIP.cpp                              //
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
#include <memory>
using Byte = unsigned short;

template<typename T>
struct Calc {
    /*-------------------------------------
      C++ creational functions normally
      return a base pointer, e.g.
      Calc<T>*, supporting dynamic
      polymorphic operations.

      We are only using static polymorphic
      operations, so this works, and is
      close to the way Rust works. 
    */
    static Calc<T> create();
    T calc(T arg1, T arg2);
};

template<typename T>
class Plus : public Calc<T> {
public:
    static Plus<T> create() {
        return Plus();
    }
    T calc(T arg1, T arg2)
    {
        return arg1 + arg2;
    }
};

template<typename T>
class Times : public Calc<T> {
public:
    static Times<T> create() {
        return Times();
    }
    T calc(T arg1, T arg2)
    {
        return arg1 * arg2;
    }
};


template<typename U, typename T>
class Demo {
public:
    Demo() {
        U oper = U::create();
    }
    T do_calc(T arg1, T arg2) {
        T rslt = oper.calc(arg1, arg2);
        result = rslt;
        return rslt;
    }
    T get_result() {
        return result;
    }
private:
    U oper;
    T result;
};
int main() {
    std::cout << "\n  -- generic DIP demo --\n";

    Demo<Plus<int>, int> demo1;
    int tmou = demo1.do_calc(40, 2);
    std::cout << "\n  The meaning of the universe is " << tmou;
    std::cout << "\n  saved result: " << demo1.get_result();
    std::cout << "\n";
    
    Demo<Times<double>, double> demo2;
    double some_number = demo2.do_calc(42.0, 2.0);
    std::cout << "\n  some-number = " << some_number;
    std::cout << "\n  saved result: " << demo2.get_result();

    std::cout << "\n\n  That's all Folks!\n\n";
}