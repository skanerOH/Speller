#include "TrieLeaf.h"

TrieLeaf::TrieLeaf()
{
    root= nullptr;
    isWordEnd=false;
    alphabet=new TrieLeaf* [alphabetSize];
    for (int i=0; i<alphabetSize; ++i)
        alphabet[i]= nullptr;
}

TrieLeaf::TrieLeaf(TrieLeaf *parent) {
    isWordEnd=false;
    alphabet=new TrieLeaf* [alphabetSize];
    root=parent;
    for (int i=0; i<alphabetSize; ++i)
        alphabet[i]= nullptr;
}

TrieLeaf::~TrieLeaf(){
    for (int i=0; i<27; ++i)
    {
        delete alphabet[i];
    }
    delete [] alphabet;
}

unsigned int TrieLeaf::GetIndexOfChar(char t)
{
    if (t==39)
        return 0;
    return (t-96);
}

void TrieLeaf::Add(std::string str) {
    if (str.length()==0) {
        this->isWordEnd = true;
    } else {
        char currChar = str[0];
        if (!(this->alphabet[GetIndexOfChar(currChar)])) {
            this->alphabet[GetIndexOfChar(currChar)] = new TrieLeaf(this);
        }
        str.erase(0, 1);
        alphabet[GetIndexOfChar(currChar)]->Add(str);
    }
}

bool TrieLeaf::Check(std::string str) {
    if (str.length()==0)
        return this->isWordEnd;
    char currChar=str[0];
    str.erase(0,1);
    if (this->alphabet[GetIndexOfChar(currChar)])
        return this->alphabet[GetIndexOfChar(currChar)]->Check(str);
    else
        return false;
}

