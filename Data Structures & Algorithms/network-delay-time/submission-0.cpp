class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map< int, vector<pair<int,int>>>m;//權重，時間
        for(int i=0;i<times.size();i++){
            m[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>>> q;

        vector<int> dist(n+1, INT_MAX);

        q.push({0,k});// 從起點 k 開始，時間為 0
        dist[k]=0;

        int maxTime=0;

        while(!q.empty()){
            auto[currTime, u]=q.top();
            q.pop();
            if(currTime>dist[u])continue;
            if(m.find(u)!=m.end()){
                for(const auto& neighbor : m[u]){
                    int v=neighbor.first;
                    int weight = neighbor.second;

                    if(currTime + weight< dist[v]){
                        dist[v]=currTime+weight;
                        q.push({dist[v],v});
                    }

                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX)return -1;
            maxTime = max(maxTime, dist[i]);

        }
        return maxTime;

    }
};
