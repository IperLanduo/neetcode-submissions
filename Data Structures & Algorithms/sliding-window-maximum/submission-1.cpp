class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int tmp = nums[0];
        for(int i=0;i<k;i++){
            tmp = max(tmp, nums[i]); 
        }
        ans.push_back(tmp);

        for(int i=k;i<nums.size();i++){
            int left = i-k;
            int right = i;

            if(nums[left] == tmp){
                //重找最大值
                tmp = nums[left + 1];

            for(int j = left + 1; j <= right; j++)tmp = max(tmp, nums[j]);
            }
            if(nums[right]>tmp)tmp=nums[right];
            ans.push_back(tmp);
        }
        return ans;
    }
};
