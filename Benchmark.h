#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "Mode.h"

using namespace std;

class Benchmark : Mode {
  private:
    double currentTime;
    // vector<double> prevTimes;
    string passageType;
    string passage;
    int wordCount;

  public:
    Benchmark() {
        currentTime = 0.0;
        passageType = "";
        passage = "";
        wordCount = 0;
    }
    void BenchmarkStart();
    // void SetCurrentTime();
    // void displayPrevTimes() const;
    // int getWordCount() const;
    // void setPassageType();
    // void setWordCount();
    // string getPassageType () const;
    // double getCurrentTime() const;
};


#endif