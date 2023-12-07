#pragma once

#include <string>
#include "profile.h"

using namespace std;

class ProfileUpdater {

    private :

        string selectedProfile;
        string fileToOpen;
        int totalTestCount;

        //the new current totals that will be RETURNED and used for calculating avgs
        double totalWPM;
        double totalAccuracy;
        double totalTime;
        int totalErrors;

        void writeTotals();
        void readProfile();

    public :

        ProfileUpdater(string profileName) : selectedProfile(profileName), fileToOpen(profileName + ".txt") {}

        void setTotals(double, double, double, int, int);
        void computeAverages();

        // double getTotalWPM() {return totalWPM;}
        // double getTotalAccuracy() {return totalAccuracy;}
        // double getTotalTime() {return totalTime;}
        // int getTotalErrors() {return totalErrors;}

        //void setFileToOpen() {fileToOpen = selectedProfile + ".data";}
};