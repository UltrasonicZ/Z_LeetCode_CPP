#include <iostream>
#include "linkedlist.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0, countB = 0;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while (p1) {
            ++countA;
            p1 = p1->next;
        }
        while (p2) {
            ++countB;                      
            p2 = p2->next;
        }
        
        while (headA != headB) {
            if (countA > countB){
                headA = headA->next;
                --countA;
                continue;
            }else if (countA < countB){
                headB = headB->next;
                --countB;
                continue;
            }
            headA = headA->next;
            headB = headB->next;            
        }
        return headA;
    }
};

int main() {
    Solution sol;
    vector<int> values2{5, 0, 1};
    vector<int> values1{4, 1};
    vector<int> values3{8, 4, 5};
    ListNode* list3 = initLinkedList(values3);
    ListNode* list1 = initLinkedList(values1);
    ListNode* p = list1;
    while(p->next)
    	p = p->next;
    p->next = list3;
    display(list1);
    ListNode* list2 = initLinkedList(values2);
    p = list2;
    while(p->next)
    	p = p->next;
    p->next = list3;
    display(list2);
    ListNode* head = sol.getIntersectionNode(list1, list2);
    display(head);
    return 0;
}
