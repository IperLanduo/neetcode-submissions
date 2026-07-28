class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        vector<int>v(n,0);
        vector<int>L(n,0);
        vector<int>R(n,0);
        L[0]=height[0];
        R[n-1]=height[n-1];

        for(int i=1;i<n;i++){
            L[i]=max(L[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            R[i]=max(height[i+1],R[i+1]);
        }
        for(int i=0;i<n;i++){
            int tmp = min(L[i],R[i]);
            if(tmp>height[i])ans += (tmp-height[i]);
        }
        return ans;
    }
};
