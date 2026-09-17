/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int good = 0;
        dfs(root, root->val, good);
        return good;
    }

    void dfs(TreeNode* root, int curGreatest, int& goodNodes) {
        if(!root) return;

        if(root->val >= curGreatest) {
            ++goodNodes;
            curGreatest = root->val;
        }

        dfs(root->left, curGreatest, goodNodes);
        dfs(root->right, curGreatest, goodNodes);
    }
};
