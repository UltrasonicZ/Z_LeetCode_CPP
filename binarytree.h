#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void creBiTreeNode(vector<int> p,TreeNode *cur,int curIndex) {
    int num = p.size();
    if (num <= 0 || cur == NULL || curIndex >= num || curIndex < 0)
        return ;
    int last = num - 1;

    if (2 * curIndex + 1 <= last)
        if (p[2 * curIndex + 1] == NULL)
            cur->left = NULL;
        else
            cur->left = new TreeNode(p[2 * curIndex + 1]);
    else
        cur->left = NULL;

    if (2 * curIndex + 2 <= last)
        if (p[2 * curIndex + 2] == NULL)
            cur->right = NULL;
        else
            cur->right = new TreeNode(p[2 * curIndex + 2]);
    else
        cur->right = NULL;
    creBiTreeNode(p, cur->left, 2 * curIndex + 1);
    creBiTreeNode(p, cur->right, 2 * curIndex + 2);
}

TreeNode* creBiTree(vector<int> p) {
    if (p.size() <= 0)
        return NULL;
    TreeNode *head = new TreeNode(p[0]);
    creBiTreeNode(p, head, 0);
    return head;
}

vector<int> preOrderTraversal(TreeNode* root, vector<int>& result) {
    if (root) {
	    cout << root->val << ' ';
        result.push_back(root->val);
	    preOrderTraversal(root->left, result);
	    preOrderTraversal(root->right, result);
        return result;
    } else
        return result;
}

vector<int> inOrderTraversal(TreeNode* root, vector<int>& result) {
    if (root) {
	    inOrderTraversal(root->left, result);
	    cout << root->val << ' ';
	    result.push_back(root->val);
	    inOrderTraversal(root->right, result);
	    return result;
    } else
        return result;
}

vector<int> postOrderTraversal(TreeNode* root, vector<int>& result) {
    if (root) {
	    postOrderTraversal(root->left, result);
	    postOrderTraversal(root->right, result);
	    cout << root->val << ' ';
        result.push_back(root->val);
        return result;
    } else
        return result;
}

void displayTree(TreeNode* root) {
    vector<int> result1;
    vector<int> result2;
    vector<int> result3;
    cout << "PreOrder:\t";
    vector<int> pre = preOrderTraversal(root, result1);
    cout << endl << "InOrder:\t";
    vector<int> in = inOrderTraversal(root, result2);
    cout << endl << "PostOrder:\t";
    vector<int> post = postOrderTraversal(root, result3);
    cout << endl;
}
