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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool isSub = false;
        dfs(root, subRoot, isSub);
        return isSub;
    }

    int dfs(TreeNode* root, TreeNode* subRoot, bool& isSub) {
        if(!root) {
            return false;
        }

        if(isSameTree(root, subRoot)) {
            isSub = true;
        }

        return 1+max(dfs(root->left, subRoot, isSub), dfs(root->right, subRoot, isSub));
    }

    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) {
            return true;
        }
        if(root1 && root2 && root1->val == root2->val) {
            return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right);
        } else {
            return false;
        }
    }
};
