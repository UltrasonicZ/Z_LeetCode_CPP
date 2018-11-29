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
        if (head == NULL || head->next == NULL) return head;
    	ListNode* p = reverseList(head->next);
	head->next->next = head;
  	head->next = NULL;
	return p;
    }
};

int main() {
    int values[] = {1, 2, 3, 4, 5};
    ListNode* list = new ListNode(values[0]);
    ListNode* cur = list;
    for (int i = 1; i < 5; ++i) {
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
