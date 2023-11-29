#include "TextDisplay.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

double TextDisplay::timedDisplay() {
    
    cout << "Press enter once done with passage!" << endl << endl;
    /* cout << "\033[s" << passage;
    cout << "\033[u" << "\x1b[32m"; */
    cout << "\x1b[34m";
    cout << passage << endl << endl;
    cout << "\x1b[32m";

    auto start = high_resolution_clock::now();
    string input;
    int errors = 0;

    cout << "\033[s";
        getline(cin, input);
        userInput += input;
        cout << "\033[u";

        for (auto i(userInput.begin() ); i != userInput.end(); ++i){ // reads and compares the system prompt vs the user string
            if (*i != *(passage.begin() + distance(userInput.begin() , i))){ // if the current char (i) is not equal to the userString at i (beginning of userString (0) + distance of i)
                ++errors;
                cout << "\x1b[31m";
            } 
            else{
                cout << "\x1b[32m";
            }
            cout << *i;
        }
        cout << endl;
    

    auto end = high_resolution_clock::now();

    duration<double> timeInterval = end - start;
    duration<double> secondsInMinute = duration<double>(60.0);
    duration<double> numberOfWords = duration<double>(10.0);
    duration<double> WPM = duration<double>(numberOfWords / (timeInterval / secondsInMinute));
    
    cout << "\x1b[37mTime taken: " << timeInterval.count() << endl;
    cout << "WPM: " << WPM.count() << endl;
    cout << "Accuracy: " << static_cast<double>(passage.size() - errors) / passage.size()  * 100 << " %" << endl;
    cout << "Errors: " << errors << endl;
    


    return timeInterval.count();

    
}
int TextDisplay::lifeDisplay() {
    string input;
    int errors = 0;
    int score = 0;
    int lives = 3;

    for (int i = 0; i < wordList.size(); ++i) {
        cout << "\x1b[34m";
        cout << wordList.at(i) << endl << endl;
        cout << "\x1b[32m";

        auto start = high_resolution_clock::now();
        //while ((high_resolution_clock::now() - start) < 10.0) {
            cout << "\033[s";
            cin >> input;
        //}

        cout << "\033[u";

        for (auto j(input.begin() ); j != input.end(); ++j){ // reads and compares the system prompt vs the user string
            if (*j != *(wordList.at(i).begin() + distance(input.begin() , j))){ // if the current char (i) is not equal to the userString at i (beginning of userString (0) + distance of i)
                ++errors;
                cout << "\x1b[31m";
            } 
            else{
                cout << "\x1b[32m";
            }
            cout << *j;
        }

        if (input != wordList.at(i))
        {
            lives = lives - 1;
        }
        else
        {
            score++;
        }
        
        if (lives <= 0)
        {
            break;
        }
    }

    
    return score;
} 

//use ansi codes to change text color as running
/* 
        std::string passage;
        std::string userInput;
        std::vector<std::string> wordList;
}; */


int main () {
    /* cout << "\x1b[37mAlright yall testing" << endl;
    cout << "\x1b[31mHey yall this is wrong" << endl;
    cout << "\x1b[32mHey yall this is right" << endl;
    cout << "\x1b[37mAlright yall back to normal" << endl; */

    TextDisplay testing;
    cout << testing.timedDisplay();
    int score = testing.lifeDisplay();
    cout << "score = " << score << endl;
};

//#endif 