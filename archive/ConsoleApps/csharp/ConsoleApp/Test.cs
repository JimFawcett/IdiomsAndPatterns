/////////////////////////////////////////////////////////////
// Test1.cs - demo building and running basic project      //
//                                                         //
// Jim Fawcett, https://JimFawcett.github.io, 15 Dec 2020  //
/////////////////////////////////////////////////////////////
/*
   Create project:
   - create folder ConsoleApp
   - cd ConsoleApp
   - dotnet new Console -n ConsoleApp
   - rename Project.cs to Tes1.cs
   Build and run project:
   - dotnet run
   Clean project
   - dotnet clean
*/
using System;

namespace Test1
{
    class DemoStartup
    {
        static int count = 0;
        public int my_count { get; }
        public DemoStartup() {
            ++count;
            my_count = count;
        }
        public string helper() {
            string hlp = "hello from helper";
            return hlp;
        }
        static void Main(string[] args)
        {
            DemoStartup prog = new DemoStartup();
            Console.Write("\n  Hello test1! from obj#{0}, ", prog.my_count);
            Console.Write(" {0}", prog.helper());
            Console.Write("\n\n  That's all Folks!\n\n");
        }
    }
}
