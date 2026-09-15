class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_oil=0;
        int total_cost=0;

        int ans=0;
        int now_oil=0;
        int n=gas.size();

        for(int i=0;i<n;i++){
            total_oil+=gas[i];
            total_cost+=cost[i];
        }

        for(int i=0;i<n;i++){
            now_oil+=gas[i];
            now_oil-=cost[i];

            if(now_oil<0){
                ans=i+1;
                now_oil=0;
            }
            
        }

        if(ans==n)ans=0;
        if(total_oil<total_cost)ans=-1;

        return  ans;    
    }
};
