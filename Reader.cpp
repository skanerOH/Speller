#include "Reader.h"

inline bool Reader::IsWordsPart(char inp) {
    return ((inp == 39) || ((inp > 64) && (inp < 91)) || ((inp > 96) && (inp < 123)));
}

Reader::Reader(std::string str)
{
    words = std::shared_ptr<std::vector<std::string>> (new std::vector<std::string>);
    path=str;
};

bool Reader::FillWordsVector() {
    std::ifstream inputFile;
    inputFile.open(path);
    if (!inputFile)
    {
        return false;
    }

    char currChar;
    std::string currWord;
    while (inputFile.get(currChar))
    {
        if (IsWordsPart(currChar))
        {
            currWord.push_back(currChar);
        } else
        {
            if (currWord.length() > 0)
            {
                std::transform(currWord.begin(), currWord.end(), currWord.begin(), ::tolower);
                words->push_back(currWord);
                currWord="";
            }
        }
    }

    inputFile.close();
    return true;
}

std::shared_ptr<std::vector<std::string>> Reader::GetPtrWordsVector() {
    return words;
}

