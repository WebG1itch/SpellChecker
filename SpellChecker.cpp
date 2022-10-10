#include "SpellChecker.h"
#include <fstream>
#include <string>
#include <sstream>


SpellChecker::SpellChecker() {
    ht = new HashTable; // create the hash table
    readDictionary();
}

void SpellChecker::readDictionary() { // read each word in the dictionary and insert them into the table
    std::ifstream dictionary("Dictionary.txt"); // make sure to get rid of trailing white spaces etc.
    std::string currentLine;

    while(std::getline(dictionary, currentLine)) {
        for(int i = 0; i < currentLine.length(); i++) {
            currentLine[i] = tolower((currentLine)[i]);
        }
        currentLine.erase(currentLine.find_last_not_of(" \n\r\t\f\v") + 1);
        addToDictionary(currentLine);

    }
}

void SpellChecker::addToDictionary(std::string word) { // insert to table
    ht->insert(word);
}

void SpellChecker::checkHashTable(std::string word) { // check for a word in the table
    ht->check(word);
};