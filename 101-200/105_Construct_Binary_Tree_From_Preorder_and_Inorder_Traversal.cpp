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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
	if (preorder.empty() || inorder.empty()) return NULL;
	int root_val = preorder[0];
        TreeNode* root = new TreeNode(root_val);
        if (preStart == preEnd) return root;
	int index = 0;
	for (index = inStart; index <= inEnd && inorder[index] != root_val; ++index);
	int leftLen = index - inStart;
  	int rightLen = inEnd - index;
  	if (leftLen > 0)
	    root->left = helper(preorder, preStart + 1, preStart + leftLen, inorder, inStart, index - 1);
	if (rightLen > 0)
	    root->right = helper(preorder, preEnd - rightLen + 1, preEnd, inorder, index + 1, inEnd);
	return root;
    }
};

int preOrderTraverse(TreeNode*);

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Solution sol;
    TreeNode* root = 0;
    root = sol.buildTree(preorder, inorder);
    preOrderTraverse(root);
    return 0;
}

int preOrderTraverse(TreeNode* root) {
    if (root == NULL) return NULL;
    std::cout << root->val << std::endl;
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}
