#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using std::vector;
using std::stack;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result{};
        if (root == NULL) return result;
        stack<TreeNode*> stack1;
	    stack1.push(root);
	    while (!stack1.empty()) {
	        result.push_back(root->val);
	        if (root->right)
		        stack1.push(root->right);
	        if (root->left)
		        stack1.push(root->left);
	        root = stack1.top();
	        stack1.pop();
	    }
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
    result = sol.preorderTraversal(node1);
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
