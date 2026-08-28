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
    int idx=0;
public:
    TreeNode* DFS(vector<int>& preorder, unordered_map<int,int>& m, int l, int r) {
        if(l>r)return nullptr;
        // 1. 從 preorder[preorder_idx] 拿出當前 Root 的數值，並且讓 preorder_idx + 1
        int curr_idx = preorder[idx];
        idx++;

        // 2. 建立新的 TreeNode (例如: new TreeNode(val))
        TreeNode* node = new TreeNode(curr_idx);

        // 3. 從 m 裡面查出這個數值在 inorder 的 index (假設叫做 mid)

         int mid = m[curr_idx];
        // 4. 遞迴建立左子樹: node->left = DFS(..., l, mid - 1);
        node->left = DFS(preorder,m, l, mid-1);
        // 5. 遞迴建立右子樹: node->right = DFS(..., mid + 1, r);
        node->right = DFS(preorder,m, mid+1, r);
        // 6. 回傳建立好的節點
        return node;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }

       return DFS(preorder, m, 0, inorder.size() - 1);

    }
};
