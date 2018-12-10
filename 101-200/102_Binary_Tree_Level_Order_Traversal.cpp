#include "binarytree.h"
#include "show.h"
#include <queue>
using std::queue;
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL)
            return result;
        queue<TreeNode*> q;
	    q.push(root);
        q.push(NULL);
        vector<int> tmp;
        while (!q.empty()) {
            TreeNode* pNode = q.front();
            q.pop();
            if (pNode == NULL) {
                result.push_back(tmp);
                tmp.resize(0);
                if (q.size() > 0)
                    q.push(NULL);
            }
            else {
                tmp.push_back(pNode->val);
                if (pNode->left)
                    q.push(pNode->left);
                if (pNode->right)
                    q.push(pNode->right);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> values{3, 9, 20, NULL, NULL, 15, 7};
    TreeNode* tree = creBiTree(values);
    displayTree(tree);
    vector<vector<int> > result = sol.levelOrder(tree);
//    for (int i = 0; i < result.size(); ++i) {
// 	for (int j = 0; j < result[i].size(); ++j)
//	    cout << result[i][j] << ' ';
//        cout << endl;
//    }
    display2Dvector(result);
    return 0;
}
