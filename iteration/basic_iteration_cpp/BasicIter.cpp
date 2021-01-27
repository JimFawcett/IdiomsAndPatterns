/////////////////////////////////////////////////
// idioms::basic_iteration_cpp::BasicIter.cpp  //
//                                             //
// Jim Fawcett, 15 Sep 2020                    //
/////////////////////////////////////////////////
/*
  Idioms:
    Styles of writing brief snippets of code in
    ways that are valued by language community

  A C++ iterator is a smart pointer associated 
  with some collection, e.g., std::string or 
  std::vector<T>.   
*/
#include<ranges>
#include<iostream>
#include <algorithm>
#include <iterator>

/*-- helper function declarations --*/
void putln(size_t num = 1);
void puttxt(const std::string& txt);
template<typename C>
void put_coll(C& coll, const std::string& prefix = "");

/*-----------------------------------------------
  Define and iterate through byte array

  Iterators for native C++ arrays are just native
  pointers.  The standard library provides
  functions std::begin(...) and std::end(...) to
  return pointers to the first element and one
  past the last element, respectively.
*/
using byte = short int;
using Iter = byte*;

/*-- iterate using basic iterator interface --*/
void iterate_byte_array() {
  puttxt("-- using basic iteration --");
  byte ba[] = { 1, 2, 3, 4, 5 };
  std::cout << "\n  ";
  for(
    Iter it=std::begin(ba); 
    it != std::end(ba); 
    ++it
  )
    std::cout << *it << " ";
  putln();
}

/*-- iterate using idiomatic iterators --*/
void idiomatic_iterate_byte_array() {
  short int ba[] = { 1, 2, 3, 4, 5 };
  puttxt("-- using range-based for loop --\n  ");
  for(auto i : ba) {
    std::cout << i << " ";
  }
  putln();

  puttxt("-- using put_coll templ func --");
  put_coll(ba, "\n  ");
  putln();

  puttxt("-- using ranges::views --");
  std::cout << "\n  [";
  /* pipe ba into views::take */
  auto temp = ba | std::views::take(4);
  for(auto i : temp) {
    std::cout << i << ", ";
  }
  auto iter = std::end(ba);
  auto last = *(--iter);
  std::cout << last << "]";
  putln();

  puttxt("-- using std::for_each --\n  ");
  auto f = [](auto item) { std::cout << item << " "; };
  std::for_each(std::begin(ba), std::end(ba), f);
}

int main() {
    std::cout 
        << "\n  -- C++ iter'n over byte arrays --\n";

    iterate_byte_array();
    idiomatic_iterate_byte_array();

    std::cout << "\n\n  That's all Folks!\n\n";
}

/*-----------------------------------------------
  helper functions eliminate a few characters
  for console output
*/
void putln(size_t num) {
  for(size_t i=0; i<num; ++i)
    std::cout << "\n";
}
void puttxt(const std::string& txt) {
  std::cout << "\n  " << txt;
}
/*-- helper function displays collection items --*/
template<typename C>
void put_coll(
  C& coll, const std::string& prefix
) {
  std::cout << prefix;
  for(auto item : coll) {
    std::cout << item << " ";
  }
}
