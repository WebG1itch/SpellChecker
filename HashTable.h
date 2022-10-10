#include <iostream>
#include <vector>
#ifndef HASHING_HASHTABLE_H
#define HASHING_HASHTABLE_H


class HashTable {

    struct node { // create nodes for linked list
        node* next;
        std::string value;
    };

    node* table[26][26]; // create table of nodes
    void printRelated(int x, int y);

public:
    void insert(std::string word);
    void check(std::string word);
};

#endif //HASHING_HASHTABLE_H