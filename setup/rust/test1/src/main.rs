/////////////////////////////////////////////////////////////
// test1 - Demonstrate creating basic Rust project         //
//                                                         //
// Jim Fawcett, https://JimFawcett.github.io, 15 Dec 2010  //
/////////////////////////////////////////////////////////////
/*
    Create project:
    - from parent directory, emit command
      cargo new test1
    - cd src
    - edit contents of test1.rs
    Build and run project:
    - cargo run
    Clean project
    - cargo clean
*/

#![allow(dead_code)]
use std::io::*;

fn helper() -> String {
    let s = "helper string".to_string();
    s
}

fn flush() {
    let _ = std::io::stdout().flush();
}

fn main() {
    print!("\n  Hello, new dev - this is test1");
    // flush();
    print!(" with {}", &helper());
    // flush();
    print!("\n\n  That's all Folks!\n\n");
}
