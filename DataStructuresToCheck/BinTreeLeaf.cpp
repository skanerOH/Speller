#include "BinTreeLeaf.h"

BinTreeLeaf::BinTreeLeaf(std::string val)
{
    value=val;
    right= nullptr;
    left= nullptr;
}

BinTreeLeaf::~BinTreeLeaf()
{
    delete right;
    delete left;
}

void BinTreeLeaf::Add(std::string val)
{
    if (val.compare(value)>0)
    {
        if (right)
        {
            right->Add(val);
        } else
        {
            right=new BinTreeLeaf(val);
        }
    }
    else if (val.compare(value)<0)
    {
        if (left)
        {
            left->Add(val);
        } else
        {
            left=new BinTreeLeaf(val);
        }
    }
}

bool BinTreeLeaf::Check(std::string val){
    if (val.compare(this->value)>0)
    {
        if (this->right)
        {
            return right->Check(val);
        } else
        {
            return false;
        }
    }
    else if (val.compare(this->value)<0)
    {
        if (this->left)
        {
            return left->Check(val);
        } else
        {
            return false;
        }
    }
    else return true;
}
