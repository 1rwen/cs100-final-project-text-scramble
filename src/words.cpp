#include "words.h"

using namespace word;

void word::getTotalPassageNumber(int &listSize)
{
    // possible counts: 10, 25, 50 (int)
    // possible difficulty: e, m, h, n (char)
    // possible themes: sp, di, sh, fd, vg, lt, mu, na (string)

    int count = 0;
    char difficulty = 'n';
    std::string theme = "";
    int temp = 0;

    for (int i = 0; i < 3; ++i) //set up possible counts
    {
        if (i == 0)
        {
            count = 10;
        }
        if (i == 1)
        {
            count = 25;
        }
        if (i == 2)
        {
            count = 50;
        }

        for (int j = 0; j < 4; ++j) //possible difficulties
        {
            if (j == 0)
            {
                difficulty = 'n';
            }
            if (j == 1)
            {
                difficulty = 'e';
            }
            if (j == 2)
            {
                difficulty = 'm';
            }
            if (j == 3)
            {
                difficulty = 'h';
            }
            theme = "na";
            temp = countPassageGroup(count, difficulty, theme);
            listSize += temp;

        }
        for (int k = 0; k < 8; ++k) //possible themes
        {
            if (k == 0)
            {
                theme = "na";
            }
            if (k == 1)
            {
                theme = "sp";
            }
            if (k == 2)
            {
                theme = "di";
            }
            if (k == 3)
            {
                theme = "sh";
            }
            if (k == 4)
            {
                theme = "fd";
            }
            if (k == 5)
            {
                theme = "vg";
            }
            if (k == 6)
            {
                theme = "lt";
            }
            if (k == 7)
            {
                theme = "mu";
            }
            difficulty = 'n';
            temp = countPassageGroup(count, difficulty, theme);
            listSize += temp;
        }
    }
}

std::string word::generatePassage(int wordCount, char diff, std::string& theme)
{
    int possibleMax = countPassageGroup(wordCount, diff, theme);

    int pickPassage = rand() % (possibleMax + 1);

    std::string fName = "../text/words";
    std::string extension = ".txt";
    std::string count = std::to_string(wordCount);
    std::string difficulty = "";
    std::string type = "";
    if (diff != 'n')
    {
        difficulty = "_";
        difficulty += diff;
    }
    if (theme != "na")
    {
        type = "_";
        type += theme;
    }

    fName += count;
    fName += difficulty;
    fName += theme;
    fName += '_';
    fName += std::to_string(pickPassage);

    std::ifstream passage(fName);
    if (!passage.is_open()) {
        std::cout << "Error in opening file!";
        return "";
    }
    else {
        std::string retPassage( (std::istreambuf_iterator<char>(passage) ),
                       (std::istreambuf_iterator<char>()    ) );
        return retPassage;
    }

    return "";

    
} // use options to choose passage

std::vector<std::string> word::generateWordList(int wordCount, char diff, std::string& theme)
{
    int possibleMax = countPassageGroup(wordCount, diff, theme);

    int pickPassage = std::rand() % (possibleMax + 1);

    std::string fName = "../text/words";
    std::string extension = ".txt";
    std::string count = std::to_string(wordCount);
    std::string difficulty = "";
    std::string type = "";
    if (diff != 'n')
    {
        difficulty = "_";
        difficulty += diff;
    }
    if (theme != "na")
    {
        type = "_";
        type += theme;
    }

    fName += count;
    fName += difficulty;
    fName += theme;
    fName += '_';
    fName += std::to_string(pickPassage);
    std::vector<std::string> wordList;

    std::ifstream passage(fName);
    if (!passage.is_open()) {
        std::cout << "Error in opening file!";
        return std::vector<std::string>();
    }
    else {
        std::string line;
        while(getline(passage, line))
        {
            std::istringstream store(line);
            while (store) {
                std::string word;
                store >> word;
                wordList.push_back(word);
            }
        }
    }

    return wordList;
} // create word list for game mode

bool word::fileCheck(std::string &fileName)
{
    struct stat check;
    bool exist = (stat(fileName.c_str(), &check) == 0); // .c_str converts string to char array and stat will return 0 if no error occurs (i.e. file exists and can be accessed)
    return exist;
}

int word::countPassageGroup(int cnt, char diff, std::string& theme)
{
    std::string dir = "../text/";
    std::string prefix = "words";
    std::string extension = ".txt";
    std::string count = std::to_string(cnt);
    std::string difficulty = "";
    std::string type = "";
    if (diff != 'n')
    {
        difficulty = "_";
        difficulty += diff;
    }
    if (theme != "na")
    {
        type = "_";
        type += theme;
    }

    int passageCount = 0;
    int max = 10;

    for (int i = 0; i < max; ++i)
    {
        std::string fName = "";
        fName += dir;
        fName += prefix;
        fName += count;
        fName += difficulty;
        fName += theme;
        fName += '_';
        fName += std::to_string(i);
        fName += extension;
        bool open = fileCheck(fName);

        passageCount = i;

        if (!open)
        {
            break;
        }
    }

    return passageCount;
}




int main () {
    std::srand(time(NULL));
    int size = 0;
    getTotalPassageNumber(size);
    std::cout << size << std::endl;
    if (fileCheck("../text/words10_0.txt")) { std::cout << "file exists" << std::endl;}
    else { std::cout << "doesn't exist" << std::endl;}

    std ::string na = "na";
    std::string test = generatePassage(10, 'n', na);

    std::cout << "Test is \"" << test << "\"" << std::endl;

    //char difficulty = 'n';
    std::string theme = "sp";

    std::vector<std::string> testList = generateWordList(50, 'n', theme);

    std::cout << "Size of list is " << testList.size() << std::endl;
    std::cout << "list: ";

    for (int i = 0; i < testList.size(); ++i) {
        std::cout << testList.at(i) << " ";
    }
};


