#include "stats.h"
#include <iostream>
#include <string>
#include <map>

// void stats::updateAvg(fstream& ioFS) {
//   ifstream inFS("avgWPM.txt");
//   if (inFS.peek() == ifstream::eof()){
//     ofstream outFS;
//     outFS.open("avgWPM.txt");

//   }

// }
void stats::outputStats() {
  cout << "Here are your stats..." << endl;
  cout << "WPM (Words per minute): " << getWPM() << endl;
  cout << "Accuracy: " << getAccuracy() << endl;
  cout << "Frequent errors: " << getErrors() << endl;
  cout << "Attrition: " << getAttritionMax() << endl; // work in progress
}

void stats::addError(char _missedChar, int _frequency){
  frequent_errors.insert({ _missedChar, _frequency });
}

void stats::setRaceRecord(int _wins, int _losses){ // increment not new
  UserRaceRecord.push_back(_wins, _losses);
}

map<char, int> stats:: getErrors() {
  for (auto iter = frequent_errors.begin(); iter != frequent_errors.end(); ++iter) { 
    cout << iter->first << iter->second << "x" << endl; 
  } 

  return frequent_errors;
}

pair<int, int> stats:: getRaceRecords() {
  for (auto iter : UserRaceRecord) {
    cout << "Wins: " << iter.first << ", Losses: " << iter.second << endl;
  }
}

