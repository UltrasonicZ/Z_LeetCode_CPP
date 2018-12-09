#include <iostream>
#include "linkedlist.h"
// Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur && cur->next)
            if (cur->next->val == cur->val) 
                cur->next = cur->next->next;
            else
                cur = cur->next;
        return head;
    }
};

int main() {
    Solution sol;
    vector<int> values{1, 1, 2, 3, 3};
    ListNode* head = initLinkedList(values);
    display(head);
    ListNode* list = sol.deleteDuplicates(head);
    display(list);
}
