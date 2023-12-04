#pragma once

#include <string>
#include <map>
#include <vector>

using namespace std;

class Profile {

    private:

        //this username clarifies what we'll be reading and writing to.
        string username;
        //vector<string> usernameList;
        void createUsernamesFile();
        bool search(string&);
        void printNames();

        void createUserProfile(string&);
    
    public:

        Profile() : username("") {}

        void chooseProfile();
        void createProfile();
        void deleteProfile(string&);

        void setUsername(string& newUsername) {username = newUsername;}
        string getUsername() {return username;}
        string getUserFileName() {return username += ".data";}

};