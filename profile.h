#include <string>
#include <map>

using namespace std;

class Profile {

    private:

        //this username clarifies what we'll be reading and writing to.
        string username;
        bool userFile;
        void createUsernamesFile();
    
    public:

        Profile() : username(""), userFile(false) {}

        void chooseProfile();
        void createProfile();

        void setUsername(string newUsername) {username = newUsername;}
        string getUsername() {return username;}

        void writeProfile();
        void readProfile();

        void setHistory(double, double, map<char, int>, int, int, int);
        void printHistory();

};