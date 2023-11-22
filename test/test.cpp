include "../src/words.h"
int main () {
    std::srand(time(NULL));
    int size = 0;
    getTotalPassageNumber(size);
    std::cout << size << std::endl;
    std::string fName = "../text/words10_0.txt";
    if (fileCheck(fName)) { std::cout << "file exists" << std::endl;}
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