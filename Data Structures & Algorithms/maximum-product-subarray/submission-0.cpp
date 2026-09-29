class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int current_min=nums[0];
        int current_max=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int num=nums[i];
            int temp=current_max;
            current_max=max({num, temp*num, current_min*num});
            current_min=min({num, temp*num, current_min*num});
            ans = max(ans, current_max);
        }
        return ans;
    }
};
