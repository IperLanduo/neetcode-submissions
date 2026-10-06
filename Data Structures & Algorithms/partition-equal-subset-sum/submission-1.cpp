class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        if(target%2==1)return false;
        target = target/2;

        unordered_set<int> s;
        s.insert(0);
        for(int i=0;i<nums.size();i++){
            unordered_set<int> next_s;
            for(int cmp:s){
                if(cmp+nums[i]==target){
                    return true;
                }
                next_s.insert(cmp);
                next_s.insert(cmp+nums[i]);
            }
            s=next_s;
        }
        return false;

    }
};
