#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "Mode.h"
#include "ProfileManager.h"
#include "ProfileUpdater.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Benchmark : Mode {
  private:
    // double currentTime;
    // vector<double> prevTimes;
    // string passageType;
    // string passage;
    duration<double> wordCount;
    duration<double> wpm;
    double accuracy;
    int errors;
    duration<double> time;

  public:
    Benchmark() {
        time = duration<double>(0.0);
        wordCount = duration<double>(0.0);
        wpm = duration<double>(0.0);
        accuracy = 0.0;
        errors = 0;
        time = duration<double>(0.0);
    }
    void BenchmarkStart(ProfileManager user);
    duration<double> calcWPM(std::chrono::time_point<std::chrono::high_resolution_clock> start, std::chrono::time_point<std::chrono::high_resolution_clock> stop);
    double calcAccuracy(string prompt, string userString);
    void addErrors(string prompt, string userString);
    duration<double> calcTime(std::chrono::time_point<std::chrono::high_resolution_clock> start, std::chrono::time_point<std::chrono::high_resolution_clock> stop);
    // void SetCurrentTime();
    // void displayPrevTimes() const;
    // int getWordCount() const;
    // void setPassageType();
    // void setWordCount();
    // string getPassageType () const;
    // double getCurrentTime() const;
};


#endif