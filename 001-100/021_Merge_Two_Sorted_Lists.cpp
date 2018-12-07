#include <iostream>
#include <vector>
using std::vector;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode* pMergeHead = NULL;
        if (l1->val < l2->val) {
            pMergeHead = l1;
            pMergeHead->next = mergeTwoLists(l1->next, l2);
        }
        else {
            pMergeHead = l2;
            pMergeHead->next = mergeTwoLists(l1, l2->next);
        }
        return pMergeHead;
    }
};

ListNode* initLinkedList(vector<int> );
void display(ListNode* );

int main() {
    Solution sol;
    vector<int> values1{1, 2, 4};
    vector<int> values2{1, 3, 4};
    ListNode* list1 = initLinkedList(values1);
    display(list1);
    ListNode* list2 = initLinkedList(values2);
    display(list2);
    ListNode* list = sol.mergeTwoLists(list1, list2);
    display(list);
//    while (list) {
//   	std::cout << list->val << std::endl;
//    	list = list->next;
//    }
    return 0;
}

ListNode* initLinkedList(vector<int> values) {
    ListNode* list = new ListNode(values[0]);
    ListNode* cur = list;
    for (int i = 1; i < values.size(); ++i) {
        cur->next = new ListNode(values[i]);
        cur = cur->next;
    }
    return list;
}

void display(ListNode* list) {
    ListNode* list_cp = list;
    while (list_cp) {
        std::cout << list_cp->val << ' ';
        list_cp = list_cp->next;
    }
    std::cout << std::endl;
}
