#ifndef SPELLER_LEAF_H
#define SPELLER_LEAF_H

#include "DataStructure.h"

class BinTreeLeaf : public DataStructure
{
public:
    std::string value;
    BinTreeLeaf* right;
    BinTreeLeaf* left;

    BinTreeLeaf(std::string);


    ~BinTreeLeaf();

    void Add(std::string) override;

    bool Check(std::string) override;
};

#endif

