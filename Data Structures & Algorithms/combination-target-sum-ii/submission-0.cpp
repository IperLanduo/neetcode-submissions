class Solution {
public:
    vector<vector<int>> ans;
    void back(int total, int target, vector<int>&v, vector<int>& nums, int idx){
        if(total == target){
            ans.push_back(v);
            return ;
        }

        if(total>target||idx>=nums.size())return ;

        for(int i=idx;i<nums.size();i++){
            if(i>idx&&nums[i]==nums[i-1])continue;
            
            v.push_back(nums[i]);
            back(total+nums[i], target, v, nums, i+1);
            v.pop_back();

        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        back(0, target, v, candidates, 0);
        return ans;
    }
};
