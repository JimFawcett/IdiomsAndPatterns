/////////////////////////////////////////////////////////////
// idioms::iteration_cpp::Iteration.cpp                    //
//   - idioms are styles of writing brief snippets of code //
//     in ways that are valued by the language community   //
//   - this idiom code focuses on iteration                //
// Jim Fawcett, https://JimFawcett.github.io, 15 Sep 2020  //
/////////////////////////////////////////////////////////////
/*
  C++ std::String
  ----------------
  C++ std::String is a container of ascii characters with 
  null terminator.
  - ascii characters are all 1 byte, so String instances can 
    be indexed.

    References:
    -----------
    std::string      
      https://doc.rust-lang.org/std/string/struct.String.html
    std::ranges
      https://en.cppreference.com/w/cpp/ranges
    std::string_view
      https://en.cppreference.com/w/cpp/string/basic_string_view
    std::vector
      https://en.cppreference.com/w/cpp/container/vector
    std::distance
      https://en.cppreference.com/w/cpp/iterator/distance
    STL std::algorithms
      https://jimfawcett.github.io/CppStory_LibrarySTL.html#algor
    std::all_of ...
      https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
*/
#include<string>
#include<ranges>
#include<iostream>
#include <locale>
#include <algorithm>
#include <string_view>
#include <typeinfo>
#include <iterator>
#include <vector>

/*-- helper function --*/
void putln(size_t num = 1) {
  for(size_t i=0; i<num; ++i)
    std::cout << "\n";
}
/*-- basic string iteration demos --*/
void string_iteration() {
    std::string test_string = "a test string";
    std::cout << "\n  ascii characters from " 
              << test_string << "\n  ";

    std::string::iterator iter = test_string.begin();
    while(iter != test_string.end()) {
      char ch = *iter;
      std::cout << ch << " ";
      if(iter == test_string.end())
        break;
      ++iter;
    }
    std::cout << "\n  test_string: " << test_string;
    putln();
}
/*-- idiomatic string iteration demos --*/
void idomatic_string_iteration() {
  std::string test_string = "another test string";
  std::cout << "\n  idiomatic ascii characters from:\n  "
            << test_string << "\n  ";

  for(auto ch : test_string) {
    std::cout << ch << " ";
  }
  putln();
  char ch2 = test_string[1];
  std::cout << "\n  2nd character of " << test_string 
            << " is " << ch2;
  std::cout << "\n  test_string: " << test_string;
  putln();
}

/*-----------------------------------------------
  demonstrate all_of(...), is_alphabetic, is_..., 
  ranges, and string_view.
*/
/*-- helper function displays collection items --*/
template<typename C>
void put_coll(C& coll, const std::string& prefix = "") {
  std::cout << prefix;
  for(auto item : coll) {
    std::cout << item;
  }
}
/*-- helper function, displays test results --*/
void test(
  bool pred, 
  const std::string& src, 
  const std::string& category
) {
  if(pred)
  {
    std::cout << "\n  " << src << " is " 
              << category;
  }
  else {
    std::cout << "\n  " << src << " is not " 
              << category;
  }
}
/*-- demonstrate string adapter functions --*/
void string_adapters() {
  std::string ls = "abc123";

  /*-- are all chars alphbetic --*/

  auto is_alpha = 
    [](char ch) -> bool { 
      return std::isalpha(ch); 
    };
  test(
    std::all_of(ls.begin(), ls.end(), is_alpha),
    ls, "alphabetic"
  );
  /*-- are all chars alphanumeric --*/

  auto is_alnum = [](char ch) -> bool
                  { return std::isalnum(ch); };
  test(
    std::all_of(ls.begin(), ls.end(), is_alnum),
    ls, "alphanumeric"
  );
  /*-- are all chars ascii --*/

  auto is_ascii = [](char ch) -> bool 
                  { return 0 <= ch && ch < 128; };
  test(
    std::all_of(ls.begin(), ls.end(), is_ascii),
    ls, "ascii"
  );
  /*-- are all chars numeric --*/

  auto is_num = [](char ch) -> bool 
                { return std::isdigit(ch); };
  test(
    std::all_of(ls.begin(), ls.end(), is_num),
    ls, "numeric"
  );
  putln();

  /*-- using range::view with pipe --*/
  auto r = ls | std::views::filter(is_num);
  put_coll(r,"\n  r is ");
  /*-- 
      numeric if numeric range, r, is same size as ls 
  --*/
  test(
    std::distance(r.begin(), r.end()) == ls.size(),
    ls, "numeric"
  );
  putln();

  /*-- display chars from str slice --*/
  ls = "abc123";
  std::string_view slice{ ls };  // non-owning view
  slice.remove_prefix(2);
  slice.remove_suffix(2);
  std::cout << "\n  third and fourth chars of " 
            << ls << " are " << slice;
  put_coll(slice, "\n  slice is ");
  std::cout << "\n  ls is still " << ls;
  putln();

  /*---------------------------------------------
     Form string from numeric chars in source, ls.
     Uses std::range adapter std::view.
  */
  auto results = ls | std::views::filter(is_num);
  std::cout << "\n  numeric chars of " 
            << ls << " are ";
  for(auto r:results) {
    std::cout << r;
  }
  put_coll(results, "\n  ");

  /*---------------------------------------------
    The results item has a very ugly type.
    Uncomment lines below to see it.
    That means that std::cout << results;
    will fail to compile.
  */
  // std::cout << typeid(results).name();
  
  putln();
}

/*-----------------------------------------------
  Define and iterate through byte array
*/
using byte = short int;
using Iter = byte*;

void define_and_iterate_byte_array() {
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
void idiomatic_define_and_iterate_byte_array() {
  short int ba[] = { 1, 2, 3, 4, 5 };
  std::cout << "\n  ";
  for(auto i : ba) {
    std::cout << i << " ";
  }
  put_coll(ba, "\n  ");
  putln();

  std::cout << "\n  [";
  auto temp = ba | std::views::take(4);
  for(auto i : temp) {
    std::cout << i << ", ";
  }
  auto iter = std::end(ba);
  auto last = *(--iter);
  std::cout << last << "]";
}

int main() {
    std::cout 
        << "\n  -- demonstrate iteration --\n";

    std::cout << "\n  -- string iteration --";
    string_iteration();
    idomatic_string_iteration();
    std::cout 
        << "\n  -- string iteration adapters --";
    string_adapters();
    std::cout 
        << "\n\n  -- byte array iteration --";
    define_and_iterate_byte_array();
    std::cout 
         << "\n  -- idiomatic byte array iteration --";
    idiomatic_define_and_iterate_byte_array();

    std::cout << "\n\n  That's all Folks!\n\n";
}
