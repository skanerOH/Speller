# include "STDUnorderedMap.h"

void STDUnorderedMap::Add(std::string val) {
    unorderedMap[val] = val;
}

bool STDUnorderedMap::Check(std::string val) {
    return (unorderedMap.find(val)!=unorderedMap.end());
}

