#include "binarytree.h"

//class Solution {
//public:
//    bool isSymmetric(TreeNode* root) {
//        TreeNode* t1 = root;
//        TreeNode* t2 = invertTree(root);
//        return isSameTree(t1, t2);
//    }
//    TreeNode* invertTree(TreeNode* root) {
//        if (root == NULL)
//            return root;
//        if (root->left == NULL && root->right == NULL)
//            return root;
//        TreeNode* rtmp = root->left;
//        root->left = root->right;
//        root->right = rtmp;
//        if (root->left)
//            root->left = invertTree(root->left);
//        if(root->right)
//            root->right = invertTree(root->right);
//        return root;
//    }
//    bool isSameTree(TreeNode* p, TreeNode* q) {
//        if (p == NULL && q == NULL)
//            return true;
//        if (p == NULL || q == NULL)
//            return false;
//        if (p->val == q->val)
//            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//        else
//            return false;
//    }

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return true;
        return leftright(root->left, root->right);
    }
    bool leftright(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL || right == NULL)
            return false;
        if (left->val == right->val)
            return leftright(left->right, right->left) && leftright(left->left, right->right);
        return false;
    }
};

int main() {
    Solution sol;
//    vector<int> values{1, 2, 2, NULL, 3, NULL, 3};
    vector<int> values{1, 2, 2, 3, 4, 4, 3};   
    TreeNode* t1 = creBiTree(values);
    displayTree(t1);
//    TreeNode* t2 = sol.invertTree(t1);
//    displayTree(t2);
    cout << std::boolalpha << sol.isSymmetric(t1) << endl;
    return 0;
}
