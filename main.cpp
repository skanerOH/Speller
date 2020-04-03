#include "Checker.h"

int main() {
    Checker checker;
    checker.CheckAllTexts();
    checker.WriteErrorFiles();
    checker.PrintResults();
    return 0;
}
