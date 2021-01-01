// CreateObject::main.rs

/*---------------------------------------------------------
  - Declare DemoObj struct, used like C++ class
  - Request compiler implement traits Debug and Clone
*/
#[derive(Debug, Clone)]
pub struct DemoObj {
    name : String
}
/*-- implement functions new and name --*/
impl DemoObj {
    pub fn new(obj_name: &str) -> DemoObj {
        DemoObj {
            name: obj_name.to_string()
        }
    }
    pub fn name(&self) -> &str {
        &self.name
    }
}
/*-- Demonstrate DemoObj instance in action --*/
fn main() {
    print!("\n  -- demonstrate object creation --\n");

    let dob = DemoObj::new("Frank");
    print!("\n  DemoObj instance name is {:?}", dob.name());

    let cdob = dob.clone();
    print!("\n  name of clone is {:?}", cdob.name());

    print!("\n\n  That's all Folks!\n\n");
}
