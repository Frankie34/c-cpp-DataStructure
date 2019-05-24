#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include "LinkNode.h"
using namespace std;

class LinkList
{
public:
	LinkNode* head;
	int getLength();
	void insertNode(LinkNode* nNode);
	LinkNode* removeNode(int pos);
};

#endif
