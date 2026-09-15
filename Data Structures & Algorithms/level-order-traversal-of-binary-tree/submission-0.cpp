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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) {
            return res;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {//2,3
            vector<int> curLevel;
            int levelSize = nodes.size();
            for(int i = 0; i < levelSize; ++i) {
                if(nodes.front()->left) {
                    nodes.push(nodes.front()->left);
                }
                if(nodes.front()->right) {
                    nodes.push(nodes.front()->right);
                }
                curLevel.push_back(nodes.front()->val);
                nodes.pop();
            }
            res.push_back(curLevel);
        }

        return res;
    }
};
