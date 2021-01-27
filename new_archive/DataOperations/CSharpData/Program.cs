/*  Program.cs -- Demo Data Operations */

using System;
using System.Collections.Generic;

namespace CSharpData
{
  class Program
  {
    static void show<T>(
      IEnumerable<T> c, String msg = ""
    ) {
      Console.Write("\n  ");
      if(msg.Length > 0)
        Console.Write("{0} ", msg);
      foreach(T item in c) {
        Console.Write("{0} ", item);
      }
    }

    static void Main(string[] args)
    {
      Console.Write(
        "\n  -- C# data operations --\n"
      );
      /*
        Primitive types in C# are copy types, 
        just like C++ and Rust.
      */
      Console.Write("\n  -- integer ops --");
           
      int x = 42;
      int y = x - 2;
      Console.Write(
        "\n  x = {0}, y = {1}", x, y
      );

      x = y;
      Console.Write("\n  after copy assign:");
      Console.Write(
        "\n  x = {0}, y = {1}\n", x, y
      );
            
      /*
        Non-primitive types are handle copy types
        not instance copy.  Instances reside in
        the managed heap, and are accessed only
        through handles, like v and w, below.

        Copy construction creates a new handle to
        the original instance.  Copy assignment
        does the same thing.
      */
      Console.Write("\n  -- List<int> ops --");

      List<int> v = new List<int>();
      int[] rng = { 1, 2, 3 };
      v.AddRange(rng);
      show(v, "v = ");
            
      var w = v;
      Console.Write(
        "\n  after copy construct var w = v:"
      );
      show(v, "v = ");
      show(w, "w = ");

      w[1] = -2;
      Console.Write(
        "\n  after setting w[1] = -2:"
      );
      show(v, "v = ");
      show(w, "w = ");
      /*
        Note that both v and w show change,
        because they are both handles to same 
        managed heap instance.
      */

      Console.WriteLine(
        "\n\n  That's all Folks!\n\n"
      );
    }
  }
}
