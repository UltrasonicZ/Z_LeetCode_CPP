#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result{};
        if (root == NULL) return result;
        return helper(result, root);
    }
    vector<int> helper(vector<int>& result, TreeNode* root) {
        if (root == NULL) return result;
        helper(result, root->left);
        result.push_back(root->val);
        helper(result, root->right);
        return result;
    }
};
void preOrderTraversal(TreeNode* );
void Show(int);
int main() {
    Solution sol;
    vector<int> result{};
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    node1->right = node2;
    node2->left = node3;
    result = sol.inorderTraversal(node1);
    for_each(result.begin(), result.end(), Show);
    std::cout << std::endl;
    preOrderTraversal(node1);
    return 0;
}

void Show(int v) {
    std::cout << v << ' ';
}

void preOrderTraversal(TreeNode* root) {
    if (root) {
        std::cout << root->val << std::endl;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
