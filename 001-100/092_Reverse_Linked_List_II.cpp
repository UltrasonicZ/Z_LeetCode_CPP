#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int m, int n) {
//        if (m == n) return head;
//	ListNode* p = head;
//	ListNode* rebegin = head;
//	for (int i = 0; i < n - 1; i++, p = p->next) 
//	    if (i == m - 2)
//		rebegin = p;
//	ListNode* reend = p;
//	
// 	p = rebegin->next;	
	ListNode* prev = reend->next;
	rebegin->next = reend;
	while (prev != reend) {
	    ListNode* q = p->next;
	    p->next = prev;
	    prev = p;
	    p = q;
	}
        rebegin->next = reend;
 	return head;
    }
};
*/

class Solution {  
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        for (int i = 0; i < m - 1; i++)
            pre = pre -> next;
        ListNode* cur = pre -> next;
        for (int i = 0; i < n - m; i++) {
            ListNode* move = cur -> next; 
            cur -> next = move -> next;
            move -> next = pre -> next;
            pre -> next = move;
        }
        return new_head -> next;
    }
};

int main() {
    vector<int> values{3, 5};
    ListNode* list = new ListNode(values[0]);
    ListNode* cur = list;
    for (int i = 1; i < values.size(); ++i) {
        cur->next = new ListNode(values[i]);
        cur = cur->next;
    }

    Solution sol;
    ListNode* out;
    out = sol.reverseBetween(list, 1, 2);
    while (out) {
        cout << out->val << endl;
        out = out->next;
    }

    return 0;
}

