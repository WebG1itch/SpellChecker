#include <iostream>
#include "SpellChecker.h"

int main() {

    SpellChecker* sc = new SpellChecker(); // start the spell checker and get input from user

    std::string input;
    std::cout << "What word would you like to check?" << std::endl;
    std::cin >> input;

    sc->checkHashTable(input);
    return 0;
}