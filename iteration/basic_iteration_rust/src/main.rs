/////////////////////////////////////////////////
// idioms::basic_iteration_rust::BasicIter.rs  //
//                                             //
// Jim Fawcett, 26 Sep 2020                    //
/////////////////////////////////////////////////
/*
  Idioms:
    Styles of writing brief snippets of code in
    ways that are valued by language community

  A Rust iterator is a type defined to step 
  through some collection, e.g., String or 
  Vec<T>.   
*/
#![allow(dead_code)]
use std::fmt::Debug;
/*-----------------------------------------------
  Define and iterate through byte arrays

  Rust arrays store, and can return with len()
  their sizes.

  Code for other collection types is quite
  similar.  We will cover Strings in the next
  idiom.
*/

/*-- iterate using basic iterator interface --*/
fn iterate_byte_array() {
  /*---------------------------------------------
    std::iter() creates an iterator for any
    type that impliments trait Iterator.
    There are three forms:
    - iter() iterates over &T
    - iter_mut() iterates over &mut T
    - into_iter() iterates over T
  */
  puttxt("-- using basic iteration --");
  let ba: [u8;5] = [1, 2, 3, 4, 5];
  print!("\n  byte array length = {}\n  ", ba.len());

  let mut iter = ba.iter();
  loop {
      let opt = iter.next();
      if opt == None {
          break; 
      }
      print!("{} ", opt.unwrap());
  }
  putln();

  puttxt("-- using for-in iteration --\n  ");
  /* 
    for-in uses iter() internally, with implicit
    handling of Option
  */
  for it in 0..5 {
      print!("{} ", ba[it]);
  }
  putln();

  puttxt("-- using for-in  alt --\n  ");
  for item in ba.iter() {
      print!("{} ", item);
  }  
  putln();

  puttxt("-- using generic put_coll --\n  ");
  let iter = ba.iter();
  put_coll(iter);
  putln();

  puttxt("-- using iterator adapter --\n  ");
  /* reset iter */
  let iter = ba.iter();
  iter.for_each(|item| { print!("{} ", item);});
  }

fn main() {
    print!("\n  -- iter'n over byte arrays --\n");

    iterate_byte_array();
    // idiomatic_iterate_byte_array();

    print!("\n\n  That's all Folks!\n\n");
}
/*-----------------------------------------------
  Helper functions here because I get tired of
  reaching for the !
*/
/*-- helper function --*/
fn putln() {
    println!();
}
/*-- emit indented text --*/
fn puttxt(t: &str) {
    print!("\n  {}", t);
}
/*-----------------------------------------------
  Emit comma delimited sequence of values from
  generic collection.

  Suggest you ignore this until we discuss
  traits.  It's here because I wanted to figure
  out how make this work.  Compiler suggestions
  were a big help.
*/
fn put_coll<C: ExactSizeIterator + Iterator>(c:C) 
     where <C as Iterator>::Item: Debug {
    let len = &c.len();
    let mut count : usize = 0;
    print!("[");
    for item in c {
        count = count + 1;
        if count < *len {
            print!("{:?}, ", item);
        }
        else {
            print!("{:?}", item);
        }
    }
    print!("]");
}
