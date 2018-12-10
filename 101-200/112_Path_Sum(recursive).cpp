#include "binarytree.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
 	if (root == NULL)
	    return false;
	if (root->left == NULL && root->right == NULL && root->val == sum)
	    return true;
   	return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main() {
    Solution sol;
    vector<int> values{5, 4, 8, 11, NULL, 13, 4, 7, 2, NULL, NULL, NULL, NULL, NULL, 1};
    TreeNode* tree = creBiTree(values);
    displayTree(tree);
    cout << std::boolalpha << sol.hasPathSum(tree, 22) << endl;
    return 0;
}
