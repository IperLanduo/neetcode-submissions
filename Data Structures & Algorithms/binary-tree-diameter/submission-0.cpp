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
    int max_height=0;
    int dfs(TreeNode* root){
        if(root==nullptr)return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);

        max_height = max(max_height,left+right);

        return max(left,right)+1;
    
    
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max_height;
    }
};
