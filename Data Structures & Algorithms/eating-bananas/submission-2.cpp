class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int right = *std::max_element(piles.begin(), piles.end());
        if(h==n){
            return right;
        }
        int ans=right;
        int left=1;
        while(left<=right){
            long long temp=0;
            int mid = (left+right)/2;
            for(int i=0;i<n;i++){
                temp += piles[i]/mid;
                if(piles[i]%mid)temp++;
            }
            if(temp>h){
                left=mid+1;
            }
            else if(temp<=h){
                ans=min(mid, ans);
                right = mid-1;
            }

        }
        return ans;
    }
};
