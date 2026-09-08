class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)return 0;
        int jump=0;
        int current_end=0;
        int farthest=0;

        for(int i=0;i<nums.size()-1;i++){
            farthest=max(i+nums[i],farthest);
            if(i==current_end){
                jump++;
                current_end=farthest;
            }
        }
        return jump;
    }
};
