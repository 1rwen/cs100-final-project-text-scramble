#include "ProfileUpdater.h"
#include <string>
#include <fstream>
#include <iostream>

void ProfileUpdater::readProfile() {

    ifstream profileData(fileToOpen.c_str());

    profileData >> totalWPM;
    profileData >> totalAccuracy;
    profileData >> totalTime;
    profileData >> totalErrors;
    profileData >> totalTestCount;

    profileData.close();

}

void ProfileUpdater::writeTotals() {

    ofstream writeNewTotals(fileToOpen.c_str());

    writeNewTotals << totalWPM << endl;
    writeNewTotals << totalAccuracy << endl;
    writeNewTotals << totalTime << endl;
    writeNewTotals << totalErrors << endl;
    writeNewTotals << totalTestCount << endl;

    writeNewTotals.close();

}

//use "filename.c_str()" to open files 

void ProfileUpdater::setTotals(double newWPM, double newAccuracy, double newTime, int newErrors, int newTestCount) {

    readProfile();

    totalWPM += newWPM;
    totalAccuracy += newAccuracy;
    totalTime += newTime;
    totalErrors += newErrors;
    totalTestCount += newTestCount;

    writeTotals();

}
