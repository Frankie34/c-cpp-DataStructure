#include "Item.h"
#include "LinkedList.h"
#include "HashMap.h"


int main() {
    
    Item nItem = new Item()
    LinkedList nLinkedList = new LinkedList();
    HashMap nHashMap = new HashMap();
    nItem.key = "hello";
    nItem.ptr = nullptr;
    nLinkedList.insertItem(nItem);
    Item *ans = nLinkedList.getItem("hello");
    cout<<*ans->key<<endl;
    return 0;
}