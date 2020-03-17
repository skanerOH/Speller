#ifndef SPELLER_DATASTRUCTURE_H
#define SPELLER_DATASTRUCTURE_H

#include <string>

//abstract class for all data structures to check

class DataStructure{
public:
    virtual void Add(std::string)=0;//adds value to data structure

    virtual bool Check(std::string)=0; //true when data structure contains value
};

#endif
