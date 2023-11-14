#ifndef WORDS_H
#define WORDS_H

#include <string>
#include <vector>
#include <sys/stat.h>
#include <fstream>
#include <time.h>
#include <iostream>

namespace word
{

    void getTotalPassageNumber(int &listSize); // store number of possible passages in folder

    std::string generatePassage(int wordCount, char diff, std::string& theme); // use options to choose passage

    std::vector<std::string> generateWordList(int wordCount, char diff, std::string& theme); // create word list for game mode

    bool fileCheck(std::string &fileName);

    int countPassageGroup(int cnt, char diff, std::string& theme);

}

#endif