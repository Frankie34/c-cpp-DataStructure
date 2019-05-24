#include "LinkedList.h"
#include "string"

void LinkedList::insertItem(Item newItem) {
    Item *newPtr = head;
    for(int i = 0;i < length-1;i++) {
        newPtr = newPtr->ptr;
    }
    newPtr->ptr = &newItem;
}

void LinkedList::removeItem(string key) {
    if(length <= 0) return;

    int flag = 0;
    Item *newPtr0 = head;
    if(newPtr0->key == key) {
        flag = 1;
        head = head->ptr;
    }

    newPtr0 = newPtr0->ptr;
    Item *newPtr1 = head;

    for(int i = 0;i < length-1;i++) {
        if(newPtr0->key == key) {
            flag = 1;
            if(newPtr0->ptr == NULL) {
                newPtr1->ptr = NULL;
            }else {
                newPtr1->ptr = newPtr0->ptr;
            }
        }
        if(newPtr0->ptr != NULL && newPtr1->ptr != NULL) {
            newPtr0 = newPtr0->ptr;
            newPtr1 = newPtr1->ptr;
        }else {
            break;
        }
    }
    return ;
}

Item* LinkedList::getItem(string key) {
    if(length <= 0) return NULL;

    int flag = 0;
    Item *newPtr = head;
    for(int i = 0;i < length() - 1;i++) {
        if(newPtr->key == key) {
            flag = 1;
            return newPtr;        
        }else {
            if(newPtr->ptr != NULL) 
                newPtr = newPtr->ptr;
        }      
    }

    return NULL;
}

void LinkedList::printList() {
    if(length <= 0) return NULL;
    
    int flag = 0;
    Item *newPtr = head;
    for(int i = 0;i < length() - 1;i++) {
        cout<<i<<newPtr->key<<endl;
        if(newPtr->ptr != NULL) 
            newPtr = newPtr->ptr;  
    }

    return;
}