#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include<bits/stdc++.h>
#include<Item.h>
#include<string>

class LinkedList {
public:
    Item *head;
    int length;
    void insertItem(Item newItem);
    void removeItem(string key);
    Item *getItem(string key);
    void printList();
};

#endif