#ifndef SPELLER_HASHTABLE_H
#define SPELLER_HASHTABLE_H

#include "DataStructure.h"
#include <map>
#include <vector>
#include <algorithm>
#include <set>

class HashTable : public DataStructure
{
private:
    std::set<std::string>** table;
    const unsigned int hashFunctionLimiter = 40000;
    unsigned int HashFunction(std::string word);
public:
    HashTable();
    ~HashTable();
    void Add(std::string) override;
    bool Check(std::string) override;
};

#endif
