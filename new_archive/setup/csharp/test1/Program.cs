/////////////////////////////////////////////////////////////
// Test1.cs - demo building and running basic project      //
//                                                         //
// Jim Fawcett, https://JimFawcett.github.io, 15 Dec 2020  //
/////////////////////////////////////////////////////////////
/*
   Create project:
   - create folder test1
   - cd test1
   - dotnet new Console -n test1
   - rename Project.cs to Test1.cs
   Build and run project:
   - dotnet run test1
   Clean project
   - dotnet clean
*/
using System;

namespace test1
{
    public class Program
    {
        static int count = 0;
        public int my_count { get; }
        public Program() {
            ++count;
            my_count = count;
        }
        public string helper() {
            string hlp = "hello from helper";
            return hlp;
        }
        static void Main(string[] args)
        {
            Program prog = new Program();
            Console.Write("\n  Hello test1! from obj#{0}, ", prog.my_count);
            Console.Write(" {0}", prog.helper());
            Console.Write("\n\n  That's all Folks!\n\n");
        }
    }
}
