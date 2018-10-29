#include <iostream>
using namespace std;
 /**
 * Definition for singly-linked list.*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3;
        l3 = new ListNode(0);
        ListNode *cur = l3;
        int add = 0;
        int sum = 0;
        while(l1 || l2){
            int l1_tmp = 0;
            int l2_tmp = 0;
            if(l1){
                l1_tmp = l1->val;
                l1 = l1->next;
            }
            if(l2){
                l2_tmp = l2->val;
                l2 = l2->next;
            }
            sum = l1_tmp + l2_tmp + add;
            if(sum >= 10){
                cur->val = sum % 10;
                add = 1;
            }
            else{
                cur->val = sum;
                add = 0;
            }
            if(l1 || l2 || add){
                if(add)
                    cur->next = new ListNode(1);
                else
                    cur->next = new ListNode(0);
                cur = cur->next;
            }
        }
        return l3;
    }
};

int main()
{
    Solution sol;
    ListNode *l1;
    l1 = new ListNode(5);
//    l1->next = new ListNode(8);
//    l1->next->next = new ListNode(3);

    ListNode *l2;
    l2 = new ListNode(5);
//    l2->next = new ListNode(6);
//    l2->next->next = new ListNode(4);

    cout << sol.addTwoNumbers(l1, l2)->val << endl;
    cout << sol.addTwoNumbers(l1, l2)->next->val << endl;
    cout << sol.addTwoNumbers(l1, l2)->next->next->val << endl;
    cout << sol.addTwoNumbers(l1, l2)->next->next->next->val << endl;
    return 0;
}
//
// Created by gz on 18-10-29.
//

