#ifndef SPELLER_CHECKER_H
#define SPELLER_CHECKER_H

#include "DataStructuresToCheck/HashTable.h"
#include "DataStructuresToCheck/BinTreeLeaf.h"
#include "DataStructuresToCheck/TrieLeaf.h"
#include "DataStructuresToCheck/STDVector.h"
#include "DataStructuresToCheck/STDUnorderedMap.h"
#include "Reader.h"
#include <iostream>
#include <random>
#include <chrono>

class Checker
{
private:
    std::shared_ptr<std::vector<std::string>> dictionary; //pointer to dictionary (vector<string> read from file by Reader)
    std::vector<std::shared_ptr<std::vector<std::string>>> texts; //vector of pointers to texts (text - vector<string> read from file by Reader)
    std::vector<std::pair<std::shared_ptr<DataStructure>, std::string>> structuresToCheck; //vector of pointers on structures that should be chacked (and their names)
    const std::string filesNames [6] ={"dictionary.txt", "Texts/alice.txt", "Texts/dracula.txt", "Texts/holmes.txt", "Texts/sherlock.txt", "Texts/tolstoy.txt"}; // array of paths to test texts
    std::vector<std::string> result; //vector of strings, where check results will be written
    const std::string errorWordsDirPath="error_Words/"; //consists path to dir where error words files are written

    void LoadDicAndTexts(); //(fills dictionary and texts fields) (used in constructor)

    void CreateStructuresToCheck(); //(fills structuresToCheck vector with concrete empty data structures (ex. Trie, ) (used in constructor)

    void FillStructuresToCheckFromDictionary(); //(adds words from dictionary to data structures in structuresToCheck vector and counts time spent on doing it) (used in constructor)

    void PushInitResults(std::shared_ptr<DataStructure>, std::string); //(Used for initial push into result vector)
public:
    Checker();

    void CheckAllTexts(); //(counts time spent on checking all texts by all data structures and write got data into result vector)

    void WriteErrorFiles(); //(searches files for error words and writes them into files called as data structure)

    void PrintResults(); //(print results to stdout)
};

#endif
