#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    ListNode *head = new ListNode(1);
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(1);
    ListNode *node4 = new ListNode(1);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = head;
    std::cout << std::boolalpha << sol.hasCycle(head) << std::endl;
    return 0;
}
