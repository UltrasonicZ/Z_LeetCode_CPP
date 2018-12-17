#include <iostream>
#include "binarytree.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL or q == NULL)
            return false;
        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
};

int main() {
    vector<int> nums1{1, 2, NULL};
    vector<int> nums2{1, NULL, 2};
    TreeNode* t1 = creBiTree(nums1);
    displayTree(t1);
    TreeNode* t2 = creBiTree(nums2);
    displayTree(t2);
    Solution sol;
    cout << std::boolalpha << sol.isSameTree(t1, t2) << endl;
    return 0;
}
