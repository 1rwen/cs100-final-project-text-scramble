/* #ifndef TEXTDISPLAY_HPP
#define TEXTDISPLAY_HPP */

#include <iostream>
#include <string>
#include <vector>

//use ansi codes to change text color as running
class TextDisplay() {
    private:
        std::string passage;
        std::string userInput;
        std::vector<std::string> wordList;
    public:
        double timedDisplay();
        int lifeDisplay();
};

//#endif 