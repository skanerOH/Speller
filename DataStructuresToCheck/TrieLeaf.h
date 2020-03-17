#ifndef SPELLER_TRIELEAF_H
#define SPELLER_TRIELEAF_H

#include "DataStructure.h"
#include <map>

class TrieLeaf : public DataStructure
{
private:
    const unsigned int alphabetSize=27;
    TrieLeaf** alphabet;
    TrieLeaf* root;
    bool isWordEnd;
    unsigned int GetIndexOfChar(char);
public:
    TrieLeaf();
    TrieLeaf(TrieLeaf*);
    void Add(std::string) override ;
    bool Check(std::string) override ;
    ~TrieLeaf();
};

#endif
