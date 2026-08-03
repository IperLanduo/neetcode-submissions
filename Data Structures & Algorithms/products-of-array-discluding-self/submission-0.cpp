class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums){
        int n=nums.size();

        vector<int> pro(n,1);
        vector<int>back(n,1);
        vector<int>ans(n,1);

        for (int i = 1; i < n; i++) {
            pro[i] = pro[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            back[i] = back[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = pro[i] * back[i];
        }

        return ans;
    }
};
