#include "binarytree.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;
        if (root->left == NULL && root->right == NULL)
            return root;
        TreeNode* rtmp = root->left;
        root->left = root->right;
        root->right = rtmp;
        if (root->left)
            root->left = invertTree(root->left);
        if(root->right)
            root->right = invertTree(root->right);
        return root;
    }
};

int main() {
    Solution sol;
    vector<int> values{4, 2, 7, 1, 3, 6, 9};
    TreeNode* tree = creBiTree(values);
    displayTree(tree);
    TreeNode* rtree = sol.invertTree(tree);
    displayTree(rtree); 
    return 0;
}

