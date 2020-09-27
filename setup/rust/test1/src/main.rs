// test1

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
    flush();
    print!(" with {}", &helper());
    flush();
    print!("\n\n  That's all Folks!\n\n");
}
