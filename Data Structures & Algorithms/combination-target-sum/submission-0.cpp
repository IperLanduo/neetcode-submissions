class Solution {
public:
    vector<vector<int>> ans;
    void back(int total, int target, vector<int>&v, vector<int>& nums, int idx){
        if(total>target||idx>=nums.size())return ;
        if(total==target){
            ans.push_back(v);
            return; 
        }
        

        back(total, target, v, nums, idx+1);
        v.push_back(nums[idx]);
        back(total+nums[idx], target, v, nums, idx);
        v.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> v;
        back(0, target, v, nums, 0);
        return ans;
    }
};
