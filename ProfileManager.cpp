#include "ProfileManager.h"
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

void ProfileManager::chooseProfile() {

    ifstream readUserFile;
    string readName;

    readUserFile.open("usernamesFile.txt");

    if (readUserFile.fail()) {

        cout << "usernames file doesn't exist, creating one" << endl;
        createUsernamesFile();

    }

    cout << "Select a username from the following list: " << endl;
    printNames();

    string userSelectInput;
    getline(cin, userSelectInput);

    bool found = search(userSelectInput);

    while (!found) {

        cout << "That profile does not exist, please try again." << endl;

        string userSelectInput;
        getline(cin, userSelectInput);

        found = search(userSelectInput);

    }

    username = userSelectInput;

    //opens the usernames file if one exists, creates one if otherwise.  
    //if (!userFile) {createUsernamesFile();}

    readUserFile.close();
    // }
    //if the user does not type in the name correctly, or types one that doesn't exist, an error
    //message will print ("invalid name, please try again") and prompt them to create a new profile if they want

}



//FOR THE HELPER FUNCTIONS!!! pass in an fstream parameter so that we don't have to keep remaking them


bool ProfileManager::search(const string& userSelectInput) {

    ifstream compareUserFile("usernamesFile.txt");

    if (compareUserFile.fail()) {

        cout << "error opening file" << endl;

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

    //adds new username to the username vector
    string newName;
    cout << "Please enter your new username: " << endl;
    getline(cin, newName);

    ofstream inUsernamesFile("usernamesFile.txt", fstream::app);

    if (inUsernamesFile.fail()) {

        cout << "There was an error opening the file" << endl;

    }

    inUsernamesFile << newName << endl;
    inUsernamesFile.close();

    createUserProfile(newName);

    //we'll need to create the files in a very specific order
    //like wpm--acc--errors--wins--losses (where the -- is a space)

}

void ProfileManager::createUserProfile(const string& newFileName) {

    string newUserFileName = newFileName + ".txt";

    ofstream newFile(newUserFileName);

    for(unsigned i = 0; i < 5; ++i) {

        newFile << 0 << endl;

    }

    newFile.close();

}

void ProfileManager::printNames() {

    ifstream printUsernames("usernamesFile.txt");

    if (printUsernames.fail()) {

        cout << "Error opening file" << endl;

    }

    string nameToPrint;
    while (printUsernames >> nameToPrint) {

        cout <<  nameToPrint << endl;

    }

    printUsernames.close();

}

void ProfileManager::createUsernamesFile () {

    string newUser;

    //file that holds usernames is created, 
    ofstream usernamesOut("usernamesFile.txt");

    cout << "Enter your new Username: " << endl;
    getline(cin, newUser);
    //cin.ignore();

    usernamesOut << newUser << endl;

    usernamesOut.close();

}

void ProfileManager::deleteProfile(const string& userToDelete) {

    username = userToDelete;
    string toDeleteString = getUserFileName();

    remove(toDeleteString.c_str());

}