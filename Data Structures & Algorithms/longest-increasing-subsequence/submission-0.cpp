class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int>dp(nums.size(),1);
        //以nums[i]為

        int max_len = 1;

        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])dp[i]=max(dp[i],dp[j]+1);
            }
        max_len = max(max_len, dp[i]);
        }
    return max_len;
    }
};
