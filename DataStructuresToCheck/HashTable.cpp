#include "HashTable.h"

unsigned int HashTable::HashFunction(std::string word) {
    unsigned int res=0;
    for (int i=0; i<word.length(); ++i)
    {
        res+=(word[i]-39)*(word[i]-39);
        res*=i;
    }
    return res % hashFunctionLimiter;
}

HashTable::HashTable()
{
    table = new std::set<std::string>* [hashFunctionLimiter];
    for (int i = 0; i<hashFunctionLimiter; ++i)
        table[i]= nullptr;
}

HashTable::~HashTable() {
    for (int i=0; i<hashFunctionLimiter; ++i)
        delete table[i];
    delete [] table;
}


void HashTable::Add(std::string word) {
    unsigned int hashFunctionValue=HashFunction(word);
    if (table[hashFunctionValue])
    {
        table[hashFunctionValue]->insert(word);
    } else
    {
        table[hashFunctionValue] = new std::set<std::string>;
        table[hashFunctionValue]->insert(word);
    }
}

bool HashTable::Check(std::string word) {
    unsigned int hashFunctionValue=HashFunction(word);
    if (!table[hashFunctionValue])
        return false;
    return table[hashFunctionValue]->count(word)!=0;
}
