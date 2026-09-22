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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        int mid = 0;
        for(int i = 0; i < inorder.size(); ++i) {
            if(inorder[i] == preorder[0]) {
                mid = i;
                break;
            }
        }

        vector<int> preLeft;
        for(int i = 1; i < 1+mid; ++i) {
            preLeft.push_back(preorder[i]);
        }
        vector<int> inLeft;
        for(int i = 0; i < mid; ++i) {
            inLeft.push_back(inorder[i]);
        }
        vector<int> preRight;
        for(int i = mid+1; i < preorder.size(); ++i) {
            preRight.push_back(preorder[i]);
        }
        vector<int>inRight;
        for(int i = mid+1; i < inorder.size(); ++i) {
            inRight.push_back(inorder[i]);
        }

        //TreeNode tmp(preorder[0]);
        TreeNode* root = new TreeNode(preorder[0]);
        root->left = buildTree(preLeft, inLeft);
        root->right = buildTree(preRight, inRight);

        return root;
    }
};
