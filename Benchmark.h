#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "Mode.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

class Benchmark : Mode {
  private:
    double currentTime;
    // vector<double> prevTimes;
    string passageType;
    string passage;
    int wordCount;
    double wpm;
    double accuracy;
    int errors;
    double time;

  public:
    Benchmark() {
        currentTime = 0.0;
        passageType = "";
        passage = "";
        wordCount = 0;
    }
    void BenchmarkStart();
    double calcWPM();
    double calcAccuracy();
    void addError();
    void setTime();
    // void SetCurrentTime();
    // void displayPrevTimes() const;
    // int getWordCount() const;
    // void setPassageType();
    // void setWordCount();
    // string getPassageType () const;
    // double getCurrentTime() const;
};


#endif