#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include<bits/stdc++.h>
#include<string>
#include<LinkedList>

class HashTable: public LinkedList{
public:
    LinkedList *array;
    int length;

    void insertItem(LinkedList *newItem);
    LinkedList *removeItem(string key);
    LinkedList *getItem(string key);

    void printTable();
    void printHistogram();

};

#endif