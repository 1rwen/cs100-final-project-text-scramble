


#include <string>
#include <vector>


class TextDisplay {
    private:
        std::string passage = "hey i just wanted to check in";
        std::string userInput = "";
        std::vector<std::string> wordList = {"James","Monica","Chris","testing","shoot"};
    public:
        double timedDisplay();
        int lifeDisplay();
};

