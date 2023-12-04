#pragma once

#include <string>
#include "profile.h"

using namespace std;

class FileManager {

    private :

        string selectedProfile;
        string fileToOpen;

        //the new current totals that will be RETURNED and used for calculating avgs
        double totalWPM;
        double totalAccuracy;
        double totalTime;
        int totalErrors;
        int totalTestCount;

        void writeTotals();
        void readProfile();

    public :

        FileManager(string profileName) : selectedProfile(profileName), fileToOpen(profileName + ".data") {}

        void setTotals(double, double, double, int, int);
        void computeAverages();

        // double getTotalWPM() {return totalWPM;}
        // double getTotalAccuracy() {return totalAccuracy;}
        // double getTotalTime() {return totalTime;}
        // int getTotalErrors() {return totalErrors;}

        //void setFileToOpen() {fileToOpen = selectedProfile + ".data";}
};