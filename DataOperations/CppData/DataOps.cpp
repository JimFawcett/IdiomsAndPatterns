/* DataOps.cpp - demo data operations */

#include <iostream>
#include <vector>
#include <string>

template <typename Coll>
void show(const Coll& c, const std::string& msg = "") {
  std::cout << "\n  ";
  if(msg.length() > 0) {
    std::cout << msg << " ";
  }
  using typename ValType = Coll::value_type;

  for(ValType item : c) {
    std::cout << item << " ";
  }
}

int main() {
    std::cout << 
      "\n  -- demonstrating data operations --\n";
    /*
      Primitive data types: int, double, ... 
      occupy contiguous regions of memory,
      so copies simply copy memory.
    */
    std::cout << "\n  -- integer ops --";

    int x = 42;
    auto y = x - 2;  // copy construction
    std::cout << "\n  x = " << x << ", y = " << y;

    x = y;              // copy assign
    std::cout << "\n  after copy assign: x = y";
    std::cout << "\n  x = " << x 
              << ", y = " << y << "\n";
   
    /*
      Most non-primitive types: Vec<T>, String, ...
      occupy memory on stack and heap,
      so they do not satisfy the copy trait
    */
    std::cout << "\n  -- Vec ops --";
    
    std::vector<int> v { 1,2,4 };
    show(v, "v = ");

    auto w = v;  // copy assign - a clone
    std::cout << 
      "\n  after copy construction: let w = v:";
    show(v, "v = ");
    show(w, "w = ");

    std::cout << "\n  set w[1] = -2";
    w[1] = -2;
    show(v, "v = ");
    show(w, "w = ");

    std::cout << "\n\n  That's all Folks!!\n\n";
}