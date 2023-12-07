#include "ProfileUpdater.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <chrono>

using namespace std::chrono;

void ProfileUpdater::readProfile() {

    ifstream profileData(fileToOpen.c_str());

    if (profileData.fail()) {

        std::runtime_error("There was an error reading the file.");

    }

    profileData >> totalWPM;
    profileData >> totalAccuracy;
    profileData >> totalTime;
    profileData >> totalErrors;
    profileData >> totalTestCount;

    profileData.close();

}

void ProfileUpdater::writeTotals() {

    ofstream writeNewTotals(fileToOpen.c_str());

    if (writeNewTotals.fail()) {

        std::runtime_error("There was an error reading the file.");

    }

    writeNewTotals << totalWPM << endl;
    writeNewTotals << totalAccuracy << endl;
    writeNewTotals << totalTime << endl;
    writeNewTotals << totalErrors << endl;
    writeNewTotals << totalTestCount << endl;

    writeNewTotals.close();

}

void ProfileUpdater::setTotals(const duration<double>& newWPM, double newAccuracy, const duration<double>& newTime, int newErrors) {

    readProfile();

    totalWPM += duration<double>(newWPM).count();
    totalAccuracy += newAccuracy;
    totalTime += duration<double>(newTime).count();
    totalErrors += newErrors;
    totalTestCount++;

    writeTotals();

}
