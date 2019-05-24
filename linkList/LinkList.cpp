#include "LinkList.h"
#include "LinkNode.h"

using namespace std;

int LinkList::getLength() {
	LinkList *nLinkList = head;
	int len = 0;
	while(nLinkList!=nullptr) {
		len++;
		nLinkList = nLinkList->ptr;
	}
	return len;
}

void LinkList::insertNode(LinkNode nNode) {
	LinkList *nLinkList = head;
	if(nLinkList == nullptr) {
		*head = new LinkNode();
		*head->val = nNode.val;
		return;
	}
        while(nLinkList->ptr!=nullptr) {
                nLinkList = nLinkList->ptr;
        }
	*nLinkList->ptr = nNode;
        return ;
}
