class Solution {
public:

    string longestPalindrome(string s) {
        int n=s.size();
        int start=0;
        int maxlen=1;
        vector<vector<bool>>dp(n, vector<bool>(n, false));;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(j==i)dp[i][j]=true;
                else if(s[i]==s[j]&&j-i<=1){
                    dp[i][j] = true;
                    if(j-i+1>maxlen){
                        maxlen = j - i + 1;
                        start = i;
                    }
                }
                else if(s[i]==s[j] && dp[i+1][j-1]==true){
                    dp[i][j]=true;
                    if(j-i+1>maxlen){
                        maxlen = j - i + 1;
                        start = i;
                    }
                }
            }

        }
        return s.substr(start,maxlen);
    }
};
