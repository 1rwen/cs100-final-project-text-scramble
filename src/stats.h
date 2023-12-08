#pragma once

#ifndef STAT_H
#define STAT_H

#include <iostream>

using namespace std;

struct Stats
{
  int numErrors;
  double accuracy;
  double WPM;
  double timeTaken;
  int attritionScore;

  Stats() : numErrors(0), accuracy(0), WPM(0), timeTaken(0), attritionScore(0) {}
};

ostream& operator << (ostream& out, const Stats& print);


#endif
