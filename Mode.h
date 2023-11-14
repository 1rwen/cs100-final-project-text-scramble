#ifndef MODE_H
#define MODE_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Mode {
//   protected: ALL PROTECTED TO BE INTEGRATED LATER
//     vector<Profile> users;
//     vector<string> userNames;
//     map<char, int> errors;
//     int errorCount;

  public:
    double calcAccuracy();
    void quit();
    double calcWPM(); 
    void addError(char error);
};


#endif