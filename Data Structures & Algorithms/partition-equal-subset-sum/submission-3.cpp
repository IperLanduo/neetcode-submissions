class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        if(target%2==1)return false;
        target = target/2;

        vector<bool>dp(target+1, false);
        dp[0]=true;
        for(int tmp:nums){
            for(int i=target; i>=tmp; i--){
                dp[i]=dp[i]||dp[i-tmp];
            }
            if(dp[target])return true;
        }
        return dp[target];

    }
};
