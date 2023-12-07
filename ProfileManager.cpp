#include "ProfileManager.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdexcept>

using namespace std;

void ProfileManager::chooseProfile() {

    ifstream readUserFile;
    string readName;

    readUserFile.open("usernamesFile.txt");

    if (readUserFile.fail()) {

        createUsernamesFile();
        return;

    }

    cout << "Select a username from the following list: " << endl;
    printNames();

    string userSelectInput;

    cin.clear();
    cin.ignore();
    getline(cin, userSelectInput);

    bool userFound = search(userSelectInput);

    while (!userFound) {

        cout << "That profile does not exist, please try again." << endl;

        string userSelectInput;
        getline(cin, userSelectInput);

        userFound = search(userSelectInput);

    }

    username = userSelectInput;

    readUserFile.close();
    
}

bool ProfileManager::search(const string& userSelectInput) {

    ifstream compareUserFile("usernamesFile.txt");

    if (compareUserFile.fail()) {

        std::runtime_error("There was an error reading the file.");

    }

    string readName;

    while (compareUserFile >> readName) {

        if (userSelectInput == readName) {
        
            setUsername(readName);
            return true;

        }

    }
    
    compareUserFile.close();
    //this assumes that the usernames didn't match
    return false;

}

void ProfileManager::createProfile() {

    string newName;
    cout << "Please enter your new username: " << endl;
    
    cin.clear();
    cin.ignore();
    getline(cin, newName);

    username = newName;

    ofstream inUsernamesFile("usernamesFile.txt", fstream::app);

    if (inUsernamesFile.fail()) {

        std::runtime_error("There was an error reading the file.");

    }

    inUsernamesFile << newName << endl;
    inUsernamesFile.close();

    createUserProfile(newName);

}

void ProfileManager::createUserProfile(const string& newFileName) {

    ofstream newFile(newFileName + ".txt");

    for (unsigned i = 0; i < 5; ++i) {

        newFile << 0 << endl;

    }

    newFile.close();

}

void ProfileManager::printNames() {

    ifstream printUsernames("usernamesFile.txt");

    if (printUsernames.fail()) {

        std::runtime_error("There was an error reading the file.");

    }

    string nameToPrint;
    while (printUsernames >> nameToPrint) {

        cout << nameToPrint << endl;

    }

    printUsernames.close();

}

void ProfileManager::createUsernamesFile () {

    string newUser;

    //file that holds usernames is created, 
    ofstream usernamesOut("usernamesFile.txt");

    if (usernamesOut.fail()) {

        std::runtime_error("There was an error reading the file.");

    }

    createProfile();

    usernamesOut << username << endl;

    usernamesOut.close();

}

void ProfileManager::deleteProfile(const string& userToDelete) {

    username = userToDelete;
    string toDeleteString = getUserFileName();

    remove(toDeleteString.c_str());

}