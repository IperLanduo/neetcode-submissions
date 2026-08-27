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
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        queue<TreeNode*> q;
        ans.push_back(root->val);
        q.push(root);
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();

            if(curr->left!=nullptr){
                int left=curr->left->val;
                ans.push_back(left);
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                int right = curr->right->val;
                ans.push_back(right);
                q.push(curr->right);
            }

        }
        sort(ans.begin(),ans.end());

        return ans[k-1];
    }
};
