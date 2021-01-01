using System;
using System.Diagnostics;

namespace timer
{
    class TimerDemo
    {
        double val = 1.01;
        double doWork(uint num) {
            double inc = 1.0;
            for (int i=0; i<num; i++) {
                val += inc;
                inc /= 2.0;
            }
            return val;
        }
        void showElapsed(TimeSpan ts) {
            // Format and display the TimeSpan value.
            string elapsedTime = String.Format("{0:00}:{1:00}:{2:00}.{3:00}",
            ts.Hours, ts.Minutes, ts.Seconds,
            ts.Milliseconds / 10);
            Console.Write("\n  RunTime " + elapsedTime);
            // Console.OpenStandardOutput().Flush();
        }
        static void Main(string[] args)
        {
            TimerDemo td = new TimerDemo();
            Stopwatch sw = new Stopwatch();

            Console.Write("\n  -- Timer Demo --");

            sw.Start();
            double rslt = td.doWork(200);
            sw.Stop();
            Console.Write("\n  work result = {0}", rslt);
            TimeSpan ts = sw.Elapsed;
            td.showElapsed(ts);

            Console.Write("\n\n  That's all Folks!\n\n");
        }
    }
}
