/* DataOps::main.rs - demo Rust Data Ops */

fn main() {
    print!(
      "\n  -- demonstrating data operations --\n"
    );
    /*
      Primitive data types: i32, f64, ... 
      occupy contiguous regions of memory, 
      so they satisfy the copy trait
    */
    print!("\n  -- integer ops --");

    let mut x :i32 = 42;
    let y = x - 2;  // copy construction
    print!("\n  x = {}, y = {}", x, y);

    x = y;              // copy assign
    print!("\n  after copy assign: x = y");
    print!("\n  x = {}, y = {}\n", x, y);
   
    /*
      Most non-primitive types: Vec<T>, String, ...
      occupy memory on stack and heap,
      so they do not satisfy the copy trait
    */
    print!("\n  -- Vec ops --");
    
    let v:Vec<i32> = vec![1,2,4];
    print!("\n  v = {:?}", v);

    let w = v;  // move assign
    print!(
      "\n  after move construction: let w = v:"
    );
    print!("\n  w = {:?}", w);
    print!(
      "\n  now v is invalid (been moved)\n"
    );

    let x = w.clone();
    print!(
      "\n  after clone operation: let x = w.clone():"
    );
    print!("\n  w = {:?}", w);
    print!("\n  x = {:?}", x);

    println!("\n\n  That's all Folks!!\n\n");
}
