#include "Checker.h"

Checker::Checker() {
    LoadDicAndTexts();
    CreateStructuresToCheck();
    FillStructuresToCheckFromDictionary();
}

void Checker::LoadDicAndTexts() {
    std::string prefix="";
    Reader reader(filesNames[0]);
    if (reader.FillWordsVector())
        dictionary = reader.GetPtrWordsVector();
    else
    {
        prefix="../";
        reader=Reader(prefix+filesNames[0]);
        if (reader.FillWordsVector())
            dictionary = reader.GetPtrWordsVector();
        else
            return;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(dictionary->begin(), dictionary->end(), g);

    for (int i=1; i<6; ++i)
    {
        reader=Reader(prefix+filesNames[i]);
        if (reader.FillWordsVector())
            texts.push_back(reader.GetPtrWordsVector());
    }
}

void Checker::CreateStructuresToCheck() {
    std::shared_ptr<DataStructure> hashtable_ptr = std::shared_ptr<DataStructure>(new HashTable());
    std::shared_ptr<DataStructure> trie_ptr = std::shared_ptr<DataStructure>(new TrieLeaf());
    std::shared_ptr<DataStructure> bst_ptr = std::shared_ptr<DataStructure>(new BinTreeLeaf(""));
    std::shared_ptr<DataStructure> stdvector_ptr = std::shared_ptr<DataStructure>(new STDVector());
    std::shared_ptr<DataStructure> stdunorderedmap_ptr = std::shared_ptr<DataStructure>(new STDUnorderedMap());

    PushInitResults(hashtable_ptr, "hashtable");
    PushInitResults(trie_ptr,"trie");
    PushInitResults(bst_ptr,"bst");
    PushInitResults(stdvector_ptr,"std_vector");
    PushInitResults(stdunorderedmap_ptr, "std_unordered_map");
}

void Checker::PushInitResults(std::shared_ptr<DataStructure> ptr, std::string name) {
    structuresToCheck.push_back(std::make_pair(ptr,name));
    result.push_back(name);
}

void Checker::FillStructuresToCheckFromDictionary() {
    for (int i=0; i<structuresToCheck.size(); ++i)
    {
        auto start = std::chrono::system_clock::now();
        for (auto word=dictionary->begin(); word<dictionary->end(); ++word)
        {
            structuresToCheck[i].first->Add((*word));
        }
        auto end = std::chrono::system_clock::now();
        result[i]+=" " + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    }
}
void Checker::CheckAllTexts() {
    unsigned int wordsCheckedCount, errorsCount;
    for (int i=0; i<structuresToCheck.size(); ++i) {
        wordsCheckedCount=0;
        errorsCount=0;
        auto start = std::chrono::system_clock::now();
        for (auto text = texts.begin(); text < texts.end(); ++text) {
            for (auto word = (*text)->begin(); word < (*text)->end(); ++word)
            {
                if (!(structuresToCheck[i].first->Check(*word)))
                    errorsCount++;
                wordsCheckedCount++;
            }
        }
        auto end = std::chrono::system_clock::now();
        result[i]+=" " + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()) + " " + std::to_string(wordsCheckedCount) + " " + std::to_string(errorsCount);
    }
}

void Checker::PrintResults() {
    for (auto res = result.begin(); res<result.end(); ++res)
    {
        std::cout << *res << std::endl;
    }
}

void Checker::WriteErrorFiles() {
    for (int i=0; i<structuresToCheck.size(); ++i) {
        std::ofstream file(errorWordsDirPath+structuresToCheck[i].second+".txt");
        bool r = file.is_open();
        for (auto text = texts.begin(); text < texts.end(); ++text) {
            for (auto word = (*text)->begin(); word < (*text)->end(); ++word)
            {
                if (!(structuresToCheck[i].first->Check(*word)))
                    file << *word+'\n';
            }
        }
        file.close();
    }
}

