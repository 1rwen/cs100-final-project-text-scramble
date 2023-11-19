
#ifndef STATS_H
#define STATS_H
#include <map>
#include <utility>
#include <vector>

using namespace std;

class stats {
  private:
    double wpm;
    double accuracy;
    char max_freq;
    int attritionMax;
    int wins;
    int losses;
    map<char, int> frequent_errors;
    vector<pair<int, int>> botRaceRecord; // might have to have to hardcode
    vector<pair<int, int>> UserRaceRecord;
  public: 
  
    void setWPM (double _wpm) { wpm = _wpm; }; // done
    void setAccuracy (double _accuracy) { accuracy = _accuracy; }; // done
    void addError (char _missedChar, int _frequency); // done
    void outputStats();
    double getWPM() { return wpm; }; // done
    double getAccuracy() { return accuracy; }; // done
    void setAttritionMax(int _maxScore) { attritionMax = _maxScore; }; // done
    int getAttritionMax() { return attritionMax; }; // done
    void setRaceRecord(int _wins, int _losses); 
    map<char, int> getErrors(); // done
    pair<int, int> getRaceRecords(); // done
    
};

#endif