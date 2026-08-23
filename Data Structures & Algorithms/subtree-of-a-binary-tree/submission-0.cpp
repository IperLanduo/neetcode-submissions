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
bool issametree(TreeNode* root, TreeNode* subroot){
     if(root==nullptr && subroot==nullptr)return true;
        if(root==nullptr || subroot==nullptr)return false;
        if(root->val!=subroot->val)return false;
    return issametree(root->left,subroot->left) &&issametree(root->right,subroot->right);

}

    bool dfs(TreeNode* root, TreeNode* subroot){
        if(root==nullptr)return false;
        if (issametree(root, subroot)) return true;
        return dfs(root->left, subroot) || dfs(root->right, subroot);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};
