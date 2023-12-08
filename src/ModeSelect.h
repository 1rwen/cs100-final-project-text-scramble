#ifndef MODESELECT_H
#define MODESELECT_H

#include "TextDisplay.h"
#include "words.h"
#include "Attrition.h"
#include "Benchmark.h"
#include "profile.h"
#include "ProfileUpdater.h"
#include "stats.h"

using namespace std;

using namespace std::chrono;

class ModeSelect {
  private:
    Stats currentStats;
    Stats bestStats;
    Stats avgStats;
    int runCount;
    Profile* currProfile;
    void computeAvg(Stats &curr, Stats& result);
    void compareStats(Stats &curr, Stats& best);
  public:
    ModeSelect(Profile& current) { 
      runCount = 0;
      currProfile = &current; 
    }
    void mainMenu();
    void ProfileEditor();
    void AttritionMode();
    void BenchmarkMode();
    void displayStats();
    void Quit();
};

#endif