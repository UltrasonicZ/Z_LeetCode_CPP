#include <iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* pAhead = start;
        ListNode* pBehind = start;
        for (int i = 0; i < n; ++i)
            pAhead = pAhead->next;
        while (pAhead->next) {
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }
        pBehind->next = pBehind->next->next;
        return start->next;
    }
};

int main() {
    Solution sol;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    ListNode* head = sol.removeNthFromEnd(node1, 2);
    while (head) {
        std::cout << head->val << std::endl;
        head = head->next;
    }
    return 0;
}

