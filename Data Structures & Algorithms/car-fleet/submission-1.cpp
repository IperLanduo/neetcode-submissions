class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ans=0;
        int n = position.size();
        vector< pair<int ,int>> car;
        for(int i=0;i<n;i++)car.push_back({position[i],speed[i]});
        sort(car.rbegin(),car.rend());

        double max_time = 0.0;

        for(int i=0;i<n;i++){
            double time = (double)(target - car[i].first) / car[i].second;
            if(time>max_time){
                ans++;
                max_time = time;
            }
        }
        return ans;

    }
};
