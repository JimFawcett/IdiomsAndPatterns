/////////////////////////////////////////////////
// idioms::iteration_cpp::StrIter.cpp          //
// - idioms: styles of writing brief snippets  //
//   of code in ways that are valued by the    //
//   language community                        //
// - this idiom code focuses on iteration      //
// Jim Fawcett, 26 Sep 2020                    //
/////////////////////////////////////////////////
/*
  C++ std::String
  ----------------
  C++ std::String is a container of ascii 
  characters with null terminator.
  - ascii characters are all 1 byte, so String 
    instances can be indexed.

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

/*-- helper function declarations --*/
void putln(size_t num = 1);
void puttxt(const std::string& txt);
template<typename C>
void put_coll(
  C& coll, const std::string& prefix = ""
);
template<typename C>
void put_coll_tight(
  C& coll, const std::string& prefix = ""
);
void test(
  bool pred, 
  const std::string& src, 
  const std::string& category
);

/*-- basic string iteration demos --*/
void string_iteration() {
    puttxt("-- basic string iteration --\n  ");
    std::string test_string = "a test string";

    std::string::iterator iter = 
        test_string.begin();
    while(iter != test_string.end()) {
      char ch = *iter;
      std::cout << ch << " ";
      if(iter == test_string.end())
        break;
      ++iter;
    }
    putln();
}
/*-- idiomatic string iteration demos --*/
void idomatic_string_iteration() {
  puttxt("-- idiomatic iteration --\n  ");
  std::string test_string = 
      "another test string";

  for(auto ch : test_string) {
    std::cout << ch << " ";
  }
  char ch2 = test_string[1];
  std::cout << "\n  2nd character of " 
            << test_string 
            << " is " << ch2;
  putln();
}

/*-----------------------------------------------
  demonstrate string iteration adapters
  -----------------------------------------------
  demonstrate all_of(...), ranges::fileter, 
  and string_view.
*/
void string_adapters() {

  puttxt("-- string iteration adapters --");

  std::string ls = "abc123";

  /*-- are all chars alphabetic? --*/
  auto is_alpha = 
    [](char ch) -> bool { 
      return std::isalpha(ch); 
    };

  test(
    std::all_of(ls.begin(), ls.end(), is_alpha),
    ls, "alphabetic"
  );
  /*-- are all chars alphanumeric? --*/
  auto is_alnum = [](char ch) -> bool
                  { return std::isalnum(ch); };
  test(
    std::all_of(ls.begin(), ls.end(), is_alnum),
    ls, "alphanumeric"
  );
  /*-- are all chars ascii? --*/
  auto is_ascii = [](char ch) -> bool 
                  { return 0 <= ch && ch < 128; };
  test(
    std::all_of(ls.begin(), ls.end(), is_ascii),
    ls, "ascii"
  );
  /*-- are all chars numeric? --*/

  auto is_num = [](char ch) -> bool 
                { return std::isdigit(ch); };
  test(
    std::all_of(ls.begin(), ls.end(), is_num),
    ls, "numeric"
  );
  putln();

  puttxt("-- using range::view with pipe --");
  std::cout << "\n  ls is " << ls;
  auto r = ls | std::views::filter(is_num);
  std::cout << "\n  numeric part of ls is ";
  put_coll_tight(r);
  /* is numeric only if filter removed nothing */
  test(
    std::distance(r.begin(), r.end()) == ls.size(),
      ls, "numeric"
  );
  putln();

  puttxt("-- iterating over string slice --");
  ls = "abc123";
  std::string_view slice{ ls };  // non-owning view
  slice.remove_prefix(2);  // remove first 2 chars
  slice.remove_suffix(2);  // remove last 2 chars
  std::cout << "\n  third and fourth chars of " 
            << ls << " are " << slice;
  std::cout << "\n  slice is " << slice;
  std::cout << "\n  ls is still " << ls;
  putln();

  /*---------------------------------------------
     Form string from numeric chars in source, ls.
     Uses std::range adapter std::view.
  */
  puttxt("-- using views::filter --");
  auto results = ls | std::views::filter(is_num);
  std::cout << "\n  numeric chars of " 
            << ls << " are ";
  for(auto r:results) {
    std::cout << r;
    // std::cout << "\n  " << typeid(r).name();
  }
  // same output as for loop above
  // put_coll_tight(results);

  /*---------------------------------------------
    The results item has a very ugly type.
    Uncomment lines below to see it.
    That means that std::cout << results;
    will fail to compile. But both the
    for loop and put_coll_tight
  */
  // std::cout << typeid(results).name();
  
  putln();
}

int main() {
    puttxt("-- demonstrate string iteration --\n");

    string_iteration();
    idomatic_string_iteration();
    string_adapters();

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
/*-- helper func displays collection items --*/
template<typename C>
void put_coll(
  C& coll, const std::string& prefix
) {
  std::cout << prefix;
  for(auto item : coll) {
    std::cout << item << " ";
  }
}
template<typename C>
void put_coll_tight(
  C& coll, const std::string& prefix
) {
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
