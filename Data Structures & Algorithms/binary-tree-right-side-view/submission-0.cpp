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
    vector<int> nodes;
    int depthSeen = 0;
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 1);
        return nodes;
    }
    void dfs(TreeNode* root, int depth) {
        if(!root) return;

        if(depth > depthSeen) {
            nodes.push_back(root->val);
            depthSeen = depth;
        }

        dfs(root->right, depth+1);
        dfs(root->left, depth+1);
    }
};
