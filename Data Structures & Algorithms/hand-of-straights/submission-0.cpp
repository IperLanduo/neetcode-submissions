class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        
        map<int,int> m;

        for(int i=0;i<hand.size();i++)m[hand[i]]++;
        
        for(auto tmp:m){
            int start = tmp.first;
            int count = tmp.second;

            if(count>0){
                for(int i=0;i<groupSize;i++){
                    if(m[start+i]<count)return false;
                    m[start+i]-=count;
                }
            }
        }

        return true;

    }
};
