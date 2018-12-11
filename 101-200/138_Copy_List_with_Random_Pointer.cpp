#include <iostream>
using std::cout;
using std::endl;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* pNode = head;
        while (pNode) {
            RandomListNode* pCloned = new RandomListNode(pNode->label);
            pCloned->next = pNode->next;
            pNode->next = pCloned;
            pNode = pCloned->next;
        }
        
        pNode = head;
        while (pNode) {
            RandomListNode* pCloned = pNode->next;
            if (pNode->random) 
                pCloned->random = pNode->random->next;
            pNode = pCloned->next;
        }
        
        pNode = head;
        RandomListNode* pClonedHead = NULL;
        RandomListNode* pClonedNode = NULL;
        if (pNode) {
            pClonedHead = pNode->next;
            pClonedNode = pNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        while (pNode) {
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        return pClonedHead;
    }
};

int main() {
    Solution sol;
    typedef RandomListNode* RLN;
    RLN node1 = new RandomListNode(1);
    RLN node2 = new RandomListNode(2);
    RLN node3 = new RandomListNode(3);
    RLN node4 = new RandomListNode(4);
    RLN node5 = new RandomListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node1->random = node3;
    node2->random = node5;
    node4->random = node2;
    for (RLN head = node1; head != NULL; head = head->next) {
	cout << head->label << '\t';
        if (head->random)
	    cout << head->random->label;
       	cout << endl;
    } 	
    return 0;
}
