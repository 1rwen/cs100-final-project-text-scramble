#pragma once

#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

        void setTotals(const duration<double>&, double, const duration<double>&, int);
        void computeAverages();

};