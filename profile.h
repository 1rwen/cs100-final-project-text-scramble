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
    
    public:

        Profile() : username("") {}

        void chooseProfile();
        void createProfile();

        void setUsername(string newUsername) {username = newUsername;}
        string getUsername() {return username;}
        string getUserFileName() {return username += ".data";}

        //put these in the file specific class :P
        // void setHistory(double, double, map<char, int>, int, int, int);
        // void printHistory();
        // void writeProfile();
        // void readProfile();

};