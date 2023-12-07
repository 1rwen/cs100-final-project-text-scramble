#pragma once

#include <string>
#include <map>
#include <vector>

using namespace std;

class ProfileManager {

    private:

        //this username clarifies what we'll be reading and writing to.
        string username;
        void createUsernamesFile();
        bool search(const string&);
        void printNames();

        void createUserProfile(const string&);
    
    public:

        Profile() : username("") {}

        void chooseProfile();
        void createProfile();
        void deleteProfile(const string&);

        void setUsername(const string& newUsername) {username = newUsername;}
        string getUsername() {return username;}
        string getUserFileName() {return username += ".txt";}

};