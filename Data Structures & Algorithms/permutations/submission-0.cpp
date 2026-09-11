class Solution {
public:
    vector<vector<int>> ans;
    void back(vector<int>&v, vector<int>& nums,vector<bool>& visit){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(visit[i]==true)continue;
            v.push_back(nums[i]);
            visit[i]=true;
            back(v,nums,visit);
            v.pop_back();
            visit[i]=false;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        vector<bool>visit(n,false);
        back(v,nums,visit);
        return ans;
    }
};
