/////////////////////////////////////////////////////////////
// Timer.cs - StopWatch demo                               //
//                                                         //
// Jim Fawcett, https://JimFawcett.github.io, 15 Dec 2020  //
/////////////////////////////////////////////////////////////

using System;
using System.Diagnostics;
using System.Threading;

namespace timer
{
    class TimerDemo
    {
        void doSleep(int num) {
            Thread.Sleep(num);
        }
        void showElapsed(TimeSpan ts) {
            // Format and display the TimeSpan value.
            string elapsedTime = String.Format("{0:00}:{1:00}:{2:00}:{3:00}",
            ts.Hours, ts.Minutes, ts.Seconds, ts.Milliseconds);
            Console.Write("\n  RunTime {0} Hrs, Mins, Secs, Millisecs", elapsedTime);
        }
        void showElapsedMicrosec(TimeSpan ts) {
            long ticks = ts.Ticks;
            long microsec = ticks/(TimeSpan.TicksPerMillisecond/1000);
            Console.Write("\n  RunTime " + microsec + " microsecs");
        }
        static void Main(string[] args)
        {
            TimerDemo td = new TimerDemo();
            Stopwatch sw = new Stopwatch();

            Console.Write("\n  -- Timer Demo --");

            int millisecs = 2345;
            Console.Write("\n  Request sleep for {0} millisecs", millisecs);
            sw.Start();
            td.doSleep(millisecs);
            sw.Stop();
            TimeSpan ts = sw.Elapsed;
            td.showElapsedMicrosec(ts);
            td.showElapsed(ts);

            Console.Write("\n\n  That's all Folks!\n\n");
        }
    }
}
