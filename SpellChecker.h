#ifndef HASHING_SPELLCHECKER_H
#define HASHING_SPELLCHECKER_H

#include "iostream"
#include "HashTable.h"

class SpellChecker {
private:
    HashTable* ht; // create the hash table
    void readDictionary();
    void addToDictionary(std::string word);

public:
    SpellChecker();
    void checkHashTable(std::string word);
};

#endif //HASHING_SPELLCHECKER_H