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
    - into_iter() takes ownership and iterates 
      over T
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
  for it in 0..ba.len() {
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
  put_coll(iter);  // see below
  putln();

  let iter = ba.iter();
  print!("\n  {}", &put_coll_to_string(iter));
  let iter = ba.iter();
  let result = clamp(&put_coll_to_string(iter), "{}");
  print!("\n  {}", &result);
  putln();

  puttxt("-- using iterator adapter --\n  ");
  /* reset iter */
  let iter = ba.iter();
  iter.for_each(|item| { print!("{} ", item);});
  }

fn main() {
    print!(
      "\n  -- iteration over byte arrays --\n"
    );

    iterate_byte_array();

    print!("\n\n  That's all Folks!\n\n");
}
/*-----------------------------------------------
  print helper functions here because I get tired
  of reaching for the !
*/
/*-- emit linefeed --*/
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
*/
// fn put_coll_alt<C: ExactSizeIterator + Iterator>(c:C) 
//      where <C as Iterator>::Item: Debug {
//     let len = &c.len();
//     let mut count : usize = 0;
//     print!("[");
//     for item in c {
//         count = count + 1;
//         if count < *len {
//             print!("{:?}, ", item);
//         }
//         else {
//             print!("{:?}", item);
//         }
//     }
//     print!("]");
// }
/*-----------------------------------------------
  Emit comma delimited sequence of values from
  generic collection.

  Traits use here is somewhat complex.  Compiler 
  suggestions were a big help.
*/
fn put_coll<C: ExactSizeIterator + Iterator>(
  mut c:C
)
     where <C as Iterator>::Item: Debug {
    print!("{:?}", c.next().unwrap());
    for item in c {
        print!(", {:?}", item);
    }
}
/*-- write comma separated list to String --*/
fn put_coll_to_string<
       C: ExactSizeIterator + Iterator
   >(mut c:C) -> String
     where <C as Iterator>::Item: Debug {
    let mut result = 
        format!("{:?}", c.next().unwrap());
    for item in c {
        result.push_str(&format!(", {:?}", item));
    }
    result
}
/*-- surround string with bookends --*/
fn clamp(body: &str, bookend: &str) -> String {
  let booker = bookend.to_string();
  if booker.chars().nth(1).is_none() {
    return body.to_string();
  }
  let mut result = String::new();
  let bked = bookend.to_string();
  let mut iter = bked.chars();
  /*-- no panic only if bked is ascii --*/
  let left = iter.next().unwrap();
  let right = iter.next().unwrap();
  result.push(left);
  result.push_str(body);
  result.push(right);
  result
}
