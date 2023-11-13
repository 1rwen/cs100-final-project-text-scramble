#include "profile.h"
#include <iostream>
#include <fstream>

using namespace std;

void Profile::chooseProfile() {
//opens the usernames file if one exists, creates one if otherwise.  
    if (!userFile) {createUsernamesFile();}

    ifstream inUserFile;
    string readName;

    inUserFile.open("usernamesFile.txt");

    if (inUserFile.fail()) {

        cout << "trouble reading file" << endl;
        return;

    }

    cout << "Please select a profile: " << endl;

    while (inUserFile >> readName) {

        cout << readName << endl;
        
    }



    //usernames file will then be read and displayed, and the user will have to type in a matching
    //username to select it.  Then, that username's file will be opened.
    //if the user does not type in the name correctly, or types one that doesn't exist, an error
    //message will print ("invalid name, please try again") and prompt them to create a new profile if they want

}

void Profile::createProfile() {



}

void Profile::createUsernamesFile () {

    string newUser;

    //file that holds usernames is created, 
    ofstream usernamesOut("usernamesFile.txt");
    userFile = true;

    cout << "Enter your new Username: " << endl;
    cin >> newUser;

    usernamesOut << newUser << endl;

    usernamesOut.close();

}