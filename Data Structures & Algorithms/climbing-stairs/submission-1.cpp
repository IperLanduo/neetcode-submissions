class Solution {
private:
    int memo[46]={0};

    int dfs(int n){
        if(n<=1)return 1;
        if(n==2) return 2; 

        if(memo[n]==0)memo[n]=dfs(n-1)+dfs(n-2);
        return memo[n];
    }

public:
    int climbStairs(int n) {
        return dfs(n);
    }
};
