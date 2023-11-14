#ifndef ATTRITION_H
#define ATTRITION_H

#include "Mode.h"

using namespace std;

class Attrition : Mode {
  private:
    int score;
    vector<string> wordList;
    int maxScore;

  public:
    void AttritionStart();
    // void setMaxScore();
    // bool timedWord(int position);
    // int getScore();
    // int getMaxScore();

};

#endif