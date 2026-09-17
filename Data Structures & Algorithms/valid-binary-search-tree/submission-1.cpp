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
    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        pair<int, int> bounds = {INT_MIN, INT_MAX};
        dfs(root, bounds, isValid);
        return isValid;
    }

    void dfs(TreeNode* root, pair<int, int> bounds, bool& isValid) {
        if(!root) {
            return;
        }

        if(root->val <= bounds.first || root->val >= bounds.second) {
            isValid = false;
        }

        dfs(root->left, {bounds.first, root->val}, isValid);
        dfs(root->right, {root->val, bounds.second}, isValid);
    }

};
