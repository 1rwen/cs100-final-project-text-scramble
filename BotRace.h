#ifndef BOTRACE_H
#define BOTRACE_H

#include "Mode.h"

using namespace std;

class BotRace : Mode {
  private:
    int botWPM;
    int winCount;
    int lossCount;
    string passage;

  public:
    void BotRaceStart();
    // void addWin();
    // void addLoss();
    // void printWLRecord();
    // int getWins();
    // int getLosses();
};


#endif