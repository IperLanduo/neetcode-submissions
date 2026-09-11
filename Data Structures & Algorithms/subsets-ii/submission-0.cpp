class Solution {
public:
vector<vector<int>> ans;
    
    void back(vector<int>& v, vector<int>& nums, int idx){
        if(idx==nums.size()){
            
            ans.push_back(v);
                
            return ;
        }

        v.push_back(nums[idx]);
        back(v, nums, idx+1);
        v.pop_back();

        while(idx+1<nums.size()&&nums[idx+1]==nums[idx])idx++;
        back(v, nums, idx + 1);

    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        back(v, nums, 0);
        return ans;
    }
};
