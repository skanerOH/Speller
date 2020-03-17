#include "STDVector.h"

void STDVector::Add(std::string val) {
    vect.push_back(val);
    isSorted = false;
}

bool STDVector::Check(std::string val) {
    if (!isSorted) {
        std::sort(vect.begin(), vect.end());
        isSorted=true;
    }
    return std::binary_search(vect.begin(), vect.end(), val);
}

