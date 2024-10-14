/////////////////////////////////////////////
// basic_dip::Program.cs                   //
//                                         //
// Jim Fawcett, 14 Feb 2021                //
/////////////////////////////////////////////
/*
  Demonstrates Dependency Inversion Principle:
    "High level modules should not depend on
      low level modules.  Both should depend
      on abstractions."

  This demonstration builds a basic demo with
  self-annunciating low level components.
    
    - High level part: Demo<T>
    - Low level parts: First, Second
    - Abstraction defined in this package: 
      - interface ISay
  The definitons of First and Second could be
  changed in any way that is compatible with 
  ISay without affecting compilation of
  Demo<T>.
*/


using System;

namespace BasicDip_C_
{
    public interface ISay {
        void set_id(uint id);
        uint get_id();
        void say();
    }

    public class First : ISay {
        public First() {
            id_ = 0;
        }
        public void set_id(uint id) {
            id_ = id;
        }
        public uint get_id() {
            return id_;
        }
        public void say() {
            Console.Write("\n  First here with id = {0}", id_);
        }
        uint id_;
    }

    public class Second : ISay {
        public Second() {
            id_ = 0;
        }
        public void set_id(uint id) {
            id_ = id;
        }
        public uint get_id() {
            return id_;
        }
        public void say() {
            Console.Write(
                "\n  Second here with id = {0}", id_
            );
        }
        uint id_;
    }

    public class Demo<T> where T : ISay, new() {
        public Demo() {
          my_say = new T();
        }
        public void set_id(uint id) {
            my_say.set_id(id);
        }
        public uint get_id() {
            return my_say.get_id();
        }
        public void say_it() {
            Console.Write(
                "\n  Demo with id {0} here", get_id()
            );
            my_say.say();
        }
        T my_say;
    }

    class Program {
        static void Main(string[] args) {
            Demo<First> df = new Demo<First>();
            df.set_id(1);
            df.say_it();
            Console.WriteLine();

            Demo<Second> ds = new Demo<Second>();
            ds.set_id(2);
            ds.say_it();

            Console.Write(
                "\n\n  That's all Folks!\n\n"
            );
        }
    }
}
