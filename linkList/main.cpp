#include "LinkNode.h"
#include "LinkList.h"
#include <iostream>

using namespace std;

int main() {
	LinkNode* node = new LinkNode();
	node->val = 6;
	//cout<<node->val<<endl;
	LinkList* list = new LinkList();
	list->insertNode(node);
	int len = list->getLength();
	cout<<len<<endl;
	return 0;
}
