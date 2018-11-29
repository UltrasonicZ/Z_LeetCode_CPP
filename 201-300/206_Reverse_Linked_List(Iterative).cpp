#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        ListNode* prev = NULL;
        while (p != NULL) {
	    ListNode* q = p->next;
 	    p->next = prev;
	    prev = p;
	    p = q;
	}
	return prev;
    }
};

int main() {
    //initialize a linked list
//    ListNode* rhead = new ListNode(1);
    //rhead->val = 1;

//    ListNode* p = rhead;
//    for (int i = 2; i <= 5; i++) { 
// 	ListNode *q = new ListNode(i);
//	p->next = q;
//        p = p->next;
//    }
//    ListNode* head = NULL;
//    ListNode* p0 = new ListNode(1);
//    ListNode* p1 = new ListNode(2);
//    ListNode* p2 = new ListNode(3);
//    ListNode* p3 = new ListNode(4);
//    ListNode* p4 = new ListNode(5);
//    head->next = p0;
//    p0->next = p1;
//    p1->next = p2;
//    p2->next = p3;
//    p3->next = p4;    
 
//    ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3)));
    int values[] = {1, 2, 3};
    ListNode* list = new ListNode(values[0]);
    ListNode* cur = list;
    for (int i = 1; i < 3; ++i) {
        cur->next = new ListNode(values[i]);
        cur = cur->next;
    }

    Solution sol;
    ListNode* out;
    out = sol.reverseList(list);
    while (out) {
      	cout << out->val << endl;
    	out = out->next;
    }

    return 0;
}
