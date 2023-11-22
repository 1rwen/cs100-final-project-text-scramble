#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>


using namespace std;
using namespace std::chrono;

// wordsPerMinute = numberOfWords / timeTaken (in minutes) i.e. 200 words / 1 min = 200 wpm 

// accuracy = net WPM (number of words you typed correctly) / gross WPM (numbers of words you typed including errors)  * 100 (to give a percentage)

// start testing with just 60 secs worth of words

int main () {
  cout << "=Benchmark Mode=" << endl;
  cout << "Select # of Words..." << endl;
  cout << "1. 10 Words" << endl;
  cout << "2. 25 Words" << endl;
  cout << "3. 50 Words" << endl;

  int userInput;

  cin >> userInput;  

  if (userInput == 1) {

    cin.clear();
    cin.ignore();

    auto start = high_resolution_clock::now();

    string prompt;
    string userString;
    ifstream inFS("10-words-prompt.txt"); // might require a file for each prompt (10 , 25, 50)

    if (!inFS.is_open()) {
      cout << "Error opening file" << endl;
      return 1;
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

    int errors = 0;

    for (auto i(prompt.begin() ); i != prompt.end(); ++i){ // reads and compares the system prompt vs the user string
      if (*i != *(userString.begin() + distance(prompt.begin() , i))){ // if the current char (i) is not equal to the userString at i (beginning of userString (0) + distance of i)
        ++errors;
      } 
    }

    duration<double> timeInterval = stop - start;
    duration<double> secondsInMinute = duration<double>(60.0);
    duration<double> numberOfWords = duration<double>(10.0);
    duration<double> WPM = duration<double>(numberOfWords / (timeInterval / secondsInMinute));
    
    cout << "Time taken: " << timeInterval.count() << endl;
    cout << "WPM: " << WPM.count() << endl;
    cout << "Accuracy: " << static_cast<double>((prompt.size() - errors)) / prompt.size()  * 100 << " %" << endl;
    cout << "Errors: " << errors << endl;
    
  }

  else if (userInput == 2) {
    
    cin.clear();
    cin.ignore();
    
    auto start = high_resolution_clock::now();

    string prompt;
    string userString;
    ifstream inFS("25-words-prompt.txt"); // might require a file for each prompt (10 , 25, 50)

    if (!inFS.is_open()) {
      cout << "Error opening file" << endl;
      return 1;
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

    int errors = 0;

    for (auto i(prompt.begin() ); i != prompt.end(); ++i){ // reads and compares the system prompt vs the user string
      if (*i != *(userString.begin() + distance(prompt.begin() , i))){ // if the current char (i) is not equal to the userString at i (beginning of userString (0) + distance of i)
        ++errors;
      } 
    }

    duration<double> timeInterval = stop - start;
    duration<double> secondsInMinute = duration<double>(60.0);
    duration<double> numberOfWords = duration<double>(25.0);
    duration<double> WPM = duration<double>(numberOfWords / (timeInterval / secondsInMinute));

    cout << "Time taken: " << timeInterval.count() << endl;
    cout << "WPM: " << WPM.count() << endl;
    cout << "Accuracy: " << static_cast<double>((prompt.size() - errors)) / prompt.size()  * 100 << " %" << endl;
    cout << "Errors: " << errors << endl;
  }

  

  else if (userInput == 3) {

    cin.clear();
    cin.ignore();
    
    auto start = high_resolution_clock::now();

    string prompt;
    string userString;
    ifstream inFS("50-words-prompt.txt"); // might require a file for each prompt (10 , 25, 50)

    if (!inFS.is_open()) {
      cout << "Error opening file" << endl;
      return 1;
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

    int errors = 0;

    for (auto i(prompt.begin() ); i != prompt.end(); ++i){ // reads and compares the system prompt vs the user string
      if (*i != *(userString.begin() + distance(prompt.begin() , i))){ // if the current char (i) is not equal to the userString at i (beginning of userString (0) + distance of i)
        ++errors;
      } 
    }

    duration<double> timeInterval = stop - start;
    duration<double> secondsInMinute = duration<double>(60.0);
    duration<double> numberOfWords = duration<double>(50.0);
    duration<double> WPM = duration<double>(numberOfWords / (timeInterval / secondsInMinute));

    cout << "Time taken: " << timeInterval.count() << endl;
    cout << "WPM: " << WPM.count() << endl;
    cout << "Accuracy: " << static_cast<double>((prompt.size() - errors)) / prompt.size()  * 100 << " %" << endl;
    cout << "Errors: " << errors << endl;
      
  }




  return 0;
}




