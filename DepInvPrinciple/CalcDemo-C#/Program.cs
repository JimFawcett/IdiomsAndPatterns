/////////////////////////////////////////
// generic_dip::Program.cs             //
//   - demonstrates Dep Inv Principle  //
//     with calculator                 //
// Jim Fawcett, 19 Jan 2021            //
/////////////////////////////////////////
/*
    C# is not expressive enough to implement
    this demo, as defined here:

    Demos Dependency Inversion Principle:
      "High level modules should not depend
       on low level modules.  Both should 
       depend on abstractions."

    This demo builds a calculator for 
    adding and multiplying two copy types.
      - High level part: Demo<U,T>
      - Low level parts: Plus<T>, Times<T>
      - Abstraction to be defined in this 
        package: 
        - Calc<T>

    The issue is that C# will not compile
    a generic application unless the generic
    parameter(s) are constrained to support
    all operations needed.  Calc needs to
    add operands and multiply operands, but
    operator+ and operator- cannot be
    overloaded for generic types.

    This would not be needed if there was
    some way to constrain the types to be
    numeric, but C# doesn't support that.

    C++ can implement the demo because it
    does a lazy syntax check of the generic
    code.  It only fails to compile if we
    instantiate the demo with a type that
    does  not implement operator+ and
    operator-.

    Rust can implement the demo because,
    even though it does an eager syntax
    check, it provides constraints in the
    form of the Add and Mul traits, so
    compilation succeeds as long as the 
    instantiated type supports those
    constraints.
*/
namespace Aaarrrgggggghhhhh {

    using System;

    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("\n\n  Out of luck!\n\n");
        }
    }
}
