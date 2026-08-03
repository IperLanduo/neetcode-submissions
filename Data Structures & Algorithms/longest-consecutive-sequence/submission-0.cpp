class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s;
        int ans=0;
        int keep=0;
        int last=0;

        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(const int&tmp:s){
            if(tmp != last+1){
                ans = max(ans, keep);
                keep = 1;
            }
            else keep++;
            last=tmp;
        }
        ans = max(ans,keep);

        return ans;
    }
};
