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
    int dfs(TreeNode* root, int k){
        if(root==nullptr)return 0;
        if(root->val >= k){
            k = root->val;
            return dfs(root->left, k) + dfs(root->right,k) + 1;
        }
        return dfs(root->left, k) + dfs(root->right,k);


    }
    int goodNodes(TreeNode* root) {
        int ans = dfs(root,INT_MIN);
        return ans;
    
    }  
};
