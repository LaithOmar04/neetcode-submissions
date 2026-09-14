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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        string tree1 = "";
        string tree2 = "";

        dfs(p, tree1);
        dfs(q, tree2);

        return tree1 == tree2; 
    }

    int dfs(TreeNode* root, string& str) {
        if(!root) {
            str += " ";
            return 0;
        }

        str += root->val;
        return 1 + max(dfs(root->left, str), dfs(root->right, str));
    }
};
