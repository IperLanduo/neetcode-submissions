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
    bool DFS(TreeNode* root, int up, int down){
        if(root==nullptr)return true;
        if(root->val<=up||root->val>=down)return false;
       
        return DFS(root->left, up, root->val) && DFS(root->right, root->val, down);

    }

    bool isValidBST(TreeNode* root) {
        return DFS(root,INT_MIN,INT_MAX);
    }
};
