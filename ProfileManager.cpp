#include "ProfileManager.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdexcept>
#include <vector>
#include <iterator>

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

        throw std::runtime_error("There was an error reading the file.");

    }

    string readName;

    while (compareUserFile >> readName) {

        if (userSelectInput == readName) {return true;}

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

        throw std::runtime_error("There was an error reading the file.");

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

        throw std::runtime_error("There was an error reading the file.");

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

        throw std::runtime_error("There was an error reading the file.");

    }

    createProfile();

    usernamesOut << username << endl;

    usernamesOut.close();

}

string ProfileManager::deleteProfile() {

    string userToDelete;

    cout << "Please enter the name of the profile you'd like to delete: " << endl;

    cin.clear();
    cin.ignore();
    getline(cin, userToDelete);

    bool userFound = search(userToDelete);

    while (!userFound) {

        cout << "That profile does not exist, please try again." << endl;
        
        cin.clear();
        cin.ignore();
        getline(cin, userToDelete);

        userFound = search(userToDelete);

    }

    while (username == userToDelete) {

        cout << "The profile you are trying to delete is currently the selected profile." << endl;
        cout << "Please pick another profile to switch to while we delete this one." << endl;

        chooseProfile();

    }

    vector<string> tempUsernameVector; 

    ifstream readUsernameFile("usernamesFile.txt");

    if (readUsernameFile.fail()) {

        throw std::runtime_error("There was an error reading the file.");

    }

    string readToVector;

    while (readUsernameFile >> readToVector) {

        if (readToVector != userToDelete) {

            tempUsernameVector.push_back(readToVector);

        }

    }

    readUsernameFile.close();

    ofstream rewriteUsernameFile("usernamesFile.txt");

    vector<string>::iterator i;

    for (i = tempUsernameVector.begin(); i != tempUsernameVector.end(); ++i) {

        rewriteUsernameFile << *i << endl;

    }

    rewriteUsernameFile.close();

    string toDeleteString = userToDelete + ".txt";

    remove(toDeleteString.c_str());

    return userToDelete;

}