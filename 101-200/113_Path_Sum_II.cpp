#include "binarytree.h"
#include "show.h"
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int> > result;
        findPath(root, sum, path, result);
        return result;
    }
    void findPath(TreeNode* root, int sum, vector<int>& path, vector<vector<int> >& result) {
        if (!root)
            return ;
        path.push_back(root->val);
        bool isLeaf = root->left == NULL && root->right == NULL;
        if (isLeaf && sum == root->val)
            result.push_back(path);
        findPath(root->left, sum - root->val, path, result);
        findPath(root->right, sum - root->val, path, result);
        path.pop_back();
    }
};

int main() {
    Solution sol;
    vector<int> values{5, 4, 8, 11, NULL, 13, 4, 7, 2, NULL, NULL, NULL, NULL, 5, 1};
    TreeNode* tree = creBiTree(values);
    displayTree(tree);
    vector<vector<int> > result = sol.pathSum(tree, 22);
    display2Dvector(result);
    return 0;
}
