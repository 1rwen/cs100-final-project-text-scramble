#include "profile.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Profile::chooseProfile() {

    // if (usernameList.empty()) {

    //     cout << "No profiles exist, please create one." << endl;

    //     createProfile();

    // }

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

    //opens the usernames file if one exists, creates one if otherwise.  
    //if (!userFile) {createUsernamesFile();}


    cout << "Please select a profile: " << endl;

    //usernames file will then be read and displayed
    while (readUserFile >> readName) {

        cout << readName << endl;
        
    }

    readUserFile.close();

    //the user will have to type in a matching username to select it.  Then, that username's file will be opened.
    string userToSelect;
    getline(cin, userToSelect);

    ifstream compareUserFile("usernamesFile.txt");
    bool found = false;

    // while (compareUserFile >> readName) {

    //     // cout << "current readName is: " << readName << endl;
    //     // cout << "current compare char is: " << userToSelect << endl;

    //     if (userToSelect == readName) {
            
    //         //cout << "here" << endl;
    //         setUsername(readName);
    //         found = true;
    //         break;

    //     }

    // }

    // while (!found) {

    //     cout << "invalid, please try again" << endl;


    // }
    //if the user does not type in the name correctly, or types one that doesn't exist, an error
    //message will print ("invalid name, please try again") and prompt them to create a new profile if they want

}



//FOR THE HELPER FUNCTIONS!!! pass in an fstream parameter so that we don't have to keep remaking them


bool Profile::search(string& userSelectInput) {


    // for (unsigned i = 0; i < usernameList.size(); ++i) {

    //     if (userSelectInput == usernameList.at(i)) {

    //         setUsername(usernameList.at(i));
    //         return true;

    //     }

    // }

    while (compareUserFile >> readName) {

        // cout << "current readName is: " << readName << endl;
        // cout << "current compare char is: " << userToSelect << endl;

        if (userToSelect == readName) {
            
            //cout << "here" << endl;
            setUsername(readName);
            return true;

        }

    }

    //this assumes that the usernames didn't match
    return false;

}

void Profile::createProfile() {

    //adds new username to the username vector
    string newName;
    cout << "Please enter your new username: " << endl;
    getline(cin, newName);

    usernameList.push_back(newName);

    //we'll need to create the files in a very specific order
    //like wpm--acc--errors--wins--losses (where the -- is a space)

    string newUserFileName = newName + ".data";

    ofstream newFile(newUserFileName);
    newFile.close();

}

void Profile::printNames() {

    // for (unsigned i = 0; i < usernameList.size(); ++i) {

    //     cout << usernameList.at(i) << endl;

    // }

}

void Profile::createUsernamesFile () {

    string newUser;

    //file that holds usernames is created, 
    ofstream usernamesOut("usernamesFile.txt");

    userFile = true;

    cout << "Enter your new Username: " << endl;
    getline(cin, newUser);
    //cin.ignore();

    usernamesOut << newUser << endl;

    usernamesOut.close();

}