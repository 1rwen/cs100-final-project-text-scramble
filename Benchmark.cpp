#include "Benchmark.h"

using namespace std;
using namespace std::chrono;

void Benchmark::BenchmarkStart() {
    cout << "Starting Benchmark Test..." << endl << endl;
    cout << "Select # of Words..." << endl;
    cout << "1. 10 Words" << endl;
    cout << "2. 25 Words" << endl;
    cout << "3. 50 Words" << endl;

    int userInput;

    cin >> userInput;  

    if (userInput == 1) {

        this->wordCount = duration<double>(10.0);
        cin.clear();
        cin.ignore();

        auto start = high_resolution_clock::now();

        string prompt;
        string userString;
        ifstream inFS("10-words-prompt.txt"); // might require a file for each prompt (10 , 25, 50)

        if (!inFS.is_open()) {
        cout << "Error opening file" << endl;
        return ;
        }

        else
        {
            while (inFS.good())
            {
            getline (inFS,prompt);
            cout << prompt << endl; // the prompt that the system gives

            cout << endl;
            getline(cin, userString); // the prompt that user gives

            }
        inFS.close();
        }


        auto stop = high_resolution_clock::now();

        this->accuracy = calcAccuracy(prompt, userString);
        // int errors = 0;

        
        // for (auto i(prompt.begin() ); i != prompt.end(); ++i){ // reads and compares the system prompt vs the user string
        // if (*i != *(userString.begin() + distance(prompt.begin() , i))){ // if the current char (i) is not equal to the userString at i (beginning of userString (0) + distance of i)
        //     ++errors;
        // } 
        // }

        // duration<double> timeInterval = stop - start;
        // duration<double> secondsInMinute = duration<double>(60.0);
        // duration<double> numberOfWords = duration<double>(10.0);
        // duration<double> WPM = duration<double>(numberOfWords / (timeInterval / secondsInMinute));
        
        this->wpm = calcWPM(start, stop);

        cout << "Time taken: " << time.count() << endl;
        cout << "WPM: " << wpm.count() << endl;
        cout << "Accuracy: " << this->accuracy << " %" << endl;
        cout << "Errors: " << this->errors << endl;
        
    }

    else if (userInput == 2) {
        this->wordCount = duration<double>(25.0);
        cin.clear();
        cin.ignore();
        
        auto start = high_resolution_clock::now();

        string prompt;
        string userString;
        ifstream inFS("25-words-prompt.txt"); // might require a file for each prompt (10 , 25, 50)

        if (!inFS.is_open()) {
        cout << "Error opening file" << endl;
        return;
        }

        else
        {
            while (inFS.good())
            {
            getline (inFS,prompt);
            cout << prompt << endl; // the prompt that the system gives

            cout << endl;
            getline(cin, userString); // the prompt that user gives

            }
        inFS.close();
        }


        auto stop = high_resolution_clock::now();

        this->accuracy = calcAccuracy(prompt, userString);
        // int errors = 0;

        
        // for (auto i(prompt.begin() ); i != prompt.end(); ++i){ // reads and compares the system prompt vs the user string
        // if (*i != *(userString.begin() + distance(prompt.begin() , i))){ // if the current char (i) is not equal to the userString at i (beginning of userString (0) + distance of i)
        //     ++errors;
        // } 
        // }

        // duration<double> timeInterval = stop - start;
        // duration<double> secondsInMinute = duration<double>(60.0);
        // duration<double> numberOfWords = duration<double>(10.0);
        // duration<double> WPM = duration<double>(numberOfWords / (timeInterval / secondsInMinute));
        
        this->wpm = calcWPM(start, stop);

        cout << "Time taken: " << time.count() << endl;
        cout << "WPM: " << wpm.count() << endl;
        cout << "Accuracy: " << this->accuracy << " %" << endl;
        cout << "Errors: " << this->errors << endl;
    }

    

    else if (userInput == 3) {
        this->wordCount = duration<double>(50.0);
        cin.clear();
        cin.ignore();
        
        auto start = high_resolution_clock::now();

        string prompt;
        string userString;
        ifstream inFS("50-words-prompt.txt"); // might require a file for each prompt (10 , 25, 50)

        if (!inFS.is_open()) {
        cout << "Error opening file" << endl;
        return;
        }

        else
        {
            while (inFS.good())
            {
            getline (inFS,prompt);
            cout << prompt << endl; // the prompt that the system gives

            cout << endl;
            getline(cin, userString); // the prompt that user gives

            }
        inFS.close();
        }


        auto stop = high_resolution_clock::now();

        this->accuracy = calcAccuracy(prompt, userString);
        // int errors = 0;

        
        // for (auto i(prompt.begin() ); i != prompt.end(); ++i){ // reads and compares the system prompt vs the user string
        // if (*i != *(userString.begin() + distance(prompt.begin() , i))){ // if the current char (i) is not equal to the userString at i (beginning of userString (0) + distance of i)
        //     ++errors;
        // } 
        // }

        // duration<double> timeInterval = stop - start;
        // duration<double> secondsInMinute = duration<double>(60.0);
        // duration<double> numberOfWords = duration<double>(10.0);
        // duration<double> WPM = duration<double>(numberOfWords / (timeInterval / secondsInMinute));
        
        this->wpm = calcWPM(start, stop);

        cout << "Time taken: " << time.count() << endl;
        cout << "WPM: " << wpm.count() << endl;
        cout << "Accuracy: " << this->accuracy << " %" << endl;
        cout << "Errors: " << this->errors << endl;
        
    }
    return;
}

duration<double> Benchmark::calcWPM(std::chrono::time_point<std::chrono::high_resolution_clock> start, std::chrono::time_point<std::chrono::high_resolution_clock> stop) {
    duration<double> timeInterval = calcTime(start, stop);
    duration<double> secondsInMinute = duration<double>(60.0);
    duration<double> numberOfWords = wordCount;
    duration<double> WPM = duration<double>(numberOfWords / (timeInterval / secondsInMinute));
    return WPM;
}

double Benchmark::calcAccuracy(string prompt, string userString) {
    addErrors(prompt, userString);
    return static_cast<double>((prompt.size() - this->errors)) / prompt.size()  * 100;
}

void Benchmark::addErrors(string prompt, string userString) {
    this->errors = 0;
        
    for (auto i(prompt.begin() ); i != prompt.end(); ++i){ // reads and compares the system prompt vs the user string
    if (*i != *(userString.begin() + distance(prompt.begin() , i))){ // if the current char (i) is not equal to the userString at i (beginning of userString (0) + distance of i)
        ++errors;
    } 
    }

}

duration<double> Benchmark::calcTime(std::chrono::time_point<std::chrono::high_resolution_clock> start, std::chrono::time_point<std::chrono::high_resolution_clock> stop) {
    duration<double> timeInterval = stop - start;
    this->time = timeInterval;
    return timeInterval;
}
