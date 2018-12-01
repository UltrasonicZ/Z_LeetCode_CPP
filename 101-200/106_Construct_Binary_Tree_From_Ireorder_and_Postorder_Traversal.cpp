#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* helper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (inorder.empty() || postorder.empty()) return NULL;
        int root_val = postorder[postEnd];
        TreeNode* root = new TreeNode(root_val);
        if (inStart == inEnd) return root;
        int index = 0;
        for (index = inEnd; index >= inStart && inorder[index] != root_val; --index);
        int leftLen = index - inStart;
        int rightLen = inEnd - index;
        if (leftLen > 0)
//	    root->left = helper(preorder, preStart + 1, preStart + leftLen, inorder, inStart, index - 1);
            root->left = helper(inorder, inStart, index - 1, postorder, postStart, postStart + leftLen - 1);
        if (rightLen > 0)
//	    root->right = helper(preorder, preEnd - rightLen + 1, preEnd, inorder, index + 1, inEnd);
            root->right = helper(inorder, index + 1, inEnd, postorder, postEnd - rightLen, postEnd - 1);
        return root;
    }
};

int preOrderTraverse(TreeNode*);

int main() {
    vector<int> inorder = {1, 3, 2};
    vector<int> postorder = {3, 2, 1};
    Solution sol;
    TreeNode* root = new TreeNode(0);
    root = sol.buildTree(inorder, postorder);
    preOrderTraverse(root);
    return 0;
}

int preOrderTraverse(TreeNode* root) {
    if (root == NULL) return NULL;
    std::cout << root->val << std::endl;
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}
