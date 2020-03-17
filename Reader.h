#ifndef SPELLER_READER_H
#define SPELLER_READER_H

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>

//Class made to form vector of words

class Reader
{
private:
    std::string path; //path to file to read
    std::shared_ptr<std::vector<std::string>> words; //pointer to vector of words

    inline bool IsWordsPart(char inp); // (returns true if inp is part of word)
public:
    Reader(std::string);

    bool FillWordsVector(); // (fills words field with all words in text)

    std::shared_ptr<std::vector<std::string>> GetPtrWordsVector(); // (returns pointer to vector of words, read from file)
};

#endif
