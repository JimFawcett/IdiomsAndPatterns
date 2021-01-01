// CppObject::CreateObj.cpp

#include <iostream>
#include <string>

class DemoObject {
public:
  DemoObject(const std::string& name) : name_(name) {}
  std::string name();
private:
  std::string name_;
};

std::string DemoObject::name() {
  return name_;
}

int main() {
  DemoObject dob("Zing");
  std::cout << "\n  Created DemoObject instance with name " 
            << dob.name();
  /* create clone using compiler generated copy constructor */
  DemoObject cln = dob;
  std::cout << "\n  Created DemoObject clone with name " 
            << cln.name();

  std::cout << "\n  That's all Folks" << "\n\n";
}