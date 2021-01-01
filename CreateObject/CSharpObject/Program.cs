// CSharpObject::Program.cs

using System;

namespace CSharpObject
{
    public class DemoObject {
        public DemoObject(String name) {
            name_ = name;
        }
        public String name() {
            return name_;
        }
        public DemoObject clone() {
            DemoObject cln = new DemoObject(name_);
            return cln;
        }
        private String name_;
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("\n  -- demonstrate C# object creation --");

            DemoObject dob = new DemoObject("Ashok");
            Console.Write("\n  DemoObject created with name {0}", dob.name());

            DemoObject cln = dob.clone();
            Console.Write("\n  clone of DemoObject has name {0}", cln.name());

            Console.Write("\n\n  That's all Folks!\n\n");
        }
    }
}
