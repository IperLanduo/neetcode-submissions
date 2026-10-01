class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool>dp(n+1,false);
        dp[n]=true;

        for(int i=s.size()-1;i>=0;i--){
            for(string tmp:wordDict){
                if(i+tmp.size()<=n && s.substr(i,tmp.size())==tmp){
                    dp[i]=dp[i+tmp.size()];
                }
                if(dp[i])break;
            }
        }
        return dp[0];
    }
};
