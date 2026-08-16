class Solution {
public:
    int dfs(vector<int>&nums,vector<int>&memo, int idx){
        if(idx>=nums.size())return 0;
        if(memo[idx]!=-1)return memo[idx];
        memo[idx] = max(dfs(nums,memo,idx+1),nums[idx]+dfs(nums,memo,idx+2));
        return memo[idx];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>memo(n,-1);
        return dfs(nums,memo,0);
    }
};
