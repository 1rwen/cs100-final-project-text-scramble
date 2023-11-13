#include <string>
#include <map>
#include <vector>

using namespace std;

class Profile {

    private:

        //this username clarifies what we'll be reading and writing to.
        string username;
        vector<string> usernameList;
        //void createUsernamesFile();
        bool search(string&);
        void printNames();
    
    public:

        Profile() : username(""), usernameList(0) {}

        void chooseProfile();
        void createProfile();

        void setUsername(string newUsername) {username = newUsername;}
        string getUsername() {return username;}

        void writeProfile();
        void readProfile();

        void setHistory(double, double, map<char, int>, int, int, int);
        void printHistory();

};