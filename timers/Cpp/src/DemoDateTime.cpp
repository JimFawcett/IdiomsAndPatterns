/////////////////////////////////////////////////////////////
// DemoDateTime.cpp - using DateTime as Stopwatch          //
//                                                         //
// Jim Fawcett, https://JimFawcett.github.io, 15 Dec 2020  //
/////////////////////////////////////////////////////////////
/*
    Files Required:
    ---------------
    DemoDateTime.cpp
    DateTime.h, DateTime.cpp
    StringUtilities.h
*/
#include <iostream>
#include "DateTime.h"
#include <thread>

using namespace Utilities;

int main() {
    std::cout << "\n  -- Demo DateTime timer --";
    
    DateTime dt;
    dt.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    dt.stop();
    auto et = dt.elapsedMicroseconds();
    std::cout << "\n  Requested sleep for 50 millisecs";
    std::cout << "\n  DateTime reports " << et << " microsecs";

    std::cout << "\n\n  That's all Folks!\n\n";
}