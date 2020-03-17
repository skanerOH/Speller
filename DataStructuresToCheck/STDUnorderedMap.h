#ifndef SPELLER_STDUNORDEREDMAP_H
#define SPELLER_STDUNORDEREDMAP_H

#include <unordered_map>
#include <string>
#include "DataStructure.h"

class STDUnorderedMap : public DataStructure
{
private:
    std::unordered_map<std::string, std::string> unorderedMap;
public:
    void Add(std::string) override ;
    bool Check(std::string) override ;
};

#endif
