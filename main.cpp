#include "Mode.h"
#include "Benchmark.h"
#include "BotRace.h"
#include "Attrition.h"

using namespace std;

//Main should be updated as the sort of starting menu of the program, it accesses all other gamemodes through profile users.
//Data will be stored to the user profile and kept in local files so that it can be updated even after the program ends.

int main () {
    char input;
    Profile UserA;
    Benchmark userA;
    // Attrition userB;
    // BotRace userC;
    do {
        cout << endl;
        if (input == 'a') {
            cout << "Entering Profile Editor..." << endl;
            //createProfile();
        }
        if (input == 'b') {
            cout << "Entering Benchmark..." << endl;
            userA.BenchmarkStart();
        }
        if (input == 'c') {
            cout << "Entering Attrition..." << endl;
            // userB.AttritionStart();
        }
        if (input == 'd') {
            cout << "Entering Bot Race..." << endl; 
            // userC.BotRaceStart();           
        }
        if (input == 'q') {
            cout << "Quitting..." << endl;
            return 0;
        }
        cout << "TYPING TEST" << endl << endl;
        cout << "a. Create/Edit a Profile" << endl;
        cout << "b. Benchmark Test" << endl;
        cout << "c. Attrition" << endl;
        cout << "d. Bot Race" << endl;
        cout << "q. Quit" << endl;
        cout << "Please Select An Option: ";
    } while (cin >> input);

    return 0;
}


