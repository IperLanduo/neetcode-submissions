class Solution {
public:

    int dfs(int idx, string s, vector<int>& dp){
        if(idx>=s.size())return 1;
        if(s[idx]=='0')return 0;
        if(dp[idx]!=-1)return dp[idx];

        int res = dfs(idx+1, s, dp);
        if(idx+1<s.size()&&(s[idx]-'0')*10+(s[idx+1]-'0')<=26) res+=dfs(idx+2, s, dp);
        
        dp[idx]=res;
        return res;
    }

    int numDecodings(string s) {
        int n=s.size();
        vector<int>memo(n,-1);
        
        return dfs(0,s,memo);

    }
};
