#include "HashTable.h"
#include "TimeInterval.h"

void HashTable::insert(std::string word) {
    int x = (word)[0] % 32 - 1; // hash function that determines where the word belongs on the table
    int y = -1;
    if(word.length() > 1) {
        y = (word)[1] % 31 - 1;
    }

    if(y > -1){
        if(table[x][y] == NULL) { // creates the nodes of the linked lists when words are inserted
            node* n = new node;
            n->value = word;
            n->next = NULL;
            table[x][y] = n;
        } else {
            node* currentNode = table[x][y];
            while (currentNode->next != NULL) {
                currentNode = currentNode->next;
            }
            node* n = new node;
            n->value = word;
            n->next = NULL;
            currentNode->next = n;
        }
    }
}

void HashTable::check(std::string word) {
    int x = (word)[0] % 32 - 1; // hash function to find where input would be on the table
    int y = -1;
    if(word.length() > 1) {
        y = (word)[1] % 31 - 1;
    }

    if(y > -1) {
        if(table[x][y] == NULL) { // if it has no resemblance, return false
            std::cout << "false" << std::endl;
        } else { // if it has resemblance, is it correct?
            bool finished = false;
            node* currentNode = table[x][y];
            while(!finished) {
                if (currentNode->value.compare(word) != 0 && currentNode->next != NULL) { // compare the input word with the words in the linked list
                    currentNode = currentNode->next;
                } else if (currentNode->value.compare(word) == 0) { // if a match is found, return true
                    std::cout << "True" << std::endl;
                    finished = true;
                    printRelated(x, y); // then print the related words
                } else {
                    std::cout << "do you mean '" << table[x][y]->value << "'?" << std::endl; // if a word is close, suggest a word
                    std::string input;
                    std::cin >> input;
                    if(input == "yes") { // if yes, print true then print related words
                        std::cout << "true" << std::endl;
                        printRelated(x, y);
                    } else {
                        std::cout << "false" << std::endl; // if no, print false and exit program
                    }
                    finished = true;
                }
            }
        }
    } else {
        std::cout << "True\n'" << word << "' is the only word with just '" << word << "' as it's first two letters" << std::endl;
    }

}

void HashTable::printRelated(int x, int y) {
    TimeInterval ti; // start the time interval for search as instructed
    ti.start();

    bool done = false; // given the coordinates of the nodes on the table, finding all related words isn't that hard
    node* currentNode = table[x][y];
    while(!done){ // go through all of the nodes and print each word
        std::cout << currentNode->value << std::endl;
        if(currentNode->next != NULL) {
            currentNode = currentNode->next;
        } else { done = true; }
    }

    ti.stop();
    float time = ti.GetInterval(); // stop and print time
    std::cout << time << " micro-sec" << std::endl;
}