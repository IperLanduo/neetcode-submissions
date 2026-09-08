class Solution {
public:
    vector<vector<int> >res;
    void back(vector<int>& nums, vector<int>tmp,int idx){
        if(idx==nums.size()){
            res.push_back(tmp);
            return ;
        }
        tmp.push_back(nums[idx]);
        back(nums, tmp, idx+1);
        tmp.pop_back();
        back(nums, tmp, idx+1);
        

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        back(nums, tmp, 0);
        return res;
    }
};
