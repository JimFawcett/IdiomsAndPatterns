/////////////////////////////////////////////////////////////
// idioms::main.rs                                         //
//   - styles of writing brief snippets of code in ways    //
//     that are valued by the language community           //
// Jim Fawcett, https://JimFawcett.github.io, 15 Sep 2020  //
/////////////////////////////////////////////////////////////
/*
  Rust std::String
  ----------------
  Rust std::String is a container of utf8 characters with no null terminator.
  - utf8 characters may consist of 1 up to 6 bytes, so String instances
    can not be indexed.  Character boundaries are defined by specific
    byte sequences, used by String's chars() iterator to return sequences
    of characters.
*/
fn string_iteration() {
    let test_string = String::from("a test string");
    let mut iter = test_string.chars();  // chars returns an iterator over utf8 characters
    print!("\n  utf8 characters from {:?}:\n  ", &test_string);

    // let ls = test_string.as_str();
    // print!("\n  test_string: {:?}", ls);

    loop {
        let opt = iter.next();  // iterator returns std::option<char>
        if opt == None {
            break;
        }
        print!("{} ",opt.unwrap());  // unwrap char from Some(char)
    }
}

fn idomatic_string_iteration() {
    let test_string = String::from("another test string");
    print!("\n  idiomatic utf8 characters from {:?}:\n  ", &test_string);

    for ch in test_string.chars() {
        print!("{} ",ch);  // option handling is done implicitly in 
                           // for/in loop
    }
}
/*
  Rust byte arrays
  ----------------
  Rust arrays have sizes that must be determined at compile-time,
  even those created on the heap.

  Rust Vectors have sizes that can be determined at run-time, and
  they will readily give access to their internal heap-based arrays
  by takeing slices.

  This is perfectly data-safe, because:
  - slices have a len() function
  - even if you index past the end of the array, you can't read or
    write that memory, because a panic occurs immediately.
*/
fn define_and_iterate_byte_array() {
    let ba: [u8;5] = [1,2,3,4,5];  
    // size must be determined at compile-time, even for
    // arrays created on the heap (unlike C++)
    let max = ba.len();
    print!("\n  bytes from byte array:\n  [");
    for i in 0..max-1 {
        print!("{}, ", ba[i]);
    }
    print!("{}]", ba[max-1]);
}

fn idiomatic_define_and_iterate_byte_array() {
    let v: Vec<u8> = vec![5,4,3,2,1];
    let ba: &[u8] = &v[..];  
    /*-----------------------------------------------------
      type of slice of Vector<u8> is byte slice: &[u8]
      - slices implement len() function
      - &v[..] slice of all elements of v
      - &v[m..n] slice of elements m up to,
        but not including n 
      - Length of slice &v[..] determined by length
        of v, which can be determined at run-time.
    */
    print!("\n  idiomatic bytes from byte array:");
    print!("\n  length of byte slice: {}", ba.len());
    let max = ba.len();
    /*-- print all but the last --*/
    print!("\n  [");
    for item in ba.iter().take(max-1) {
        print!("{}, ", item);
    }
    /*-- now print the last one --*/
    print!("{}]", ba[max - 1]);

    print!("\n  printing array with implicit iteration:");
    print!("\n  {:?}", ba);
}

fn main() {
    print!("\n  -- string iteration --");
    string_iteration();
    idomatic_string_iteration();
    print!("\n\n  -- byte array iteration --");
    define_and_iterate_byte_array();
    idiomatic_define_and_iterate_byte_array();

    print!("\n\n  That's all Folks!\n");
}
