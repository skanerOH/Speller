#ifndef SPELLER_STDVECTOR_H
#define SPELLER_STDVECTOR_H

#include "DataStructure.h"
#include <vector>
#include <algorithm>

class STDVector : public DataStructure
{
private:
    std::vector<std::string> vect;
    bool isSorted=false;
public:
    void Add(std::string) override ;
    bool Check(std::string) override ;
};

#endif
