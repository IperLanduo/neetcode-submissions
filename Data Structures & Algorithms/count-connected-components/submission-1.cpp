class Solution {
public:
    int ans=0;
    void dfs(int idx, unordered_map<int, vector<int>>& m,unordered_set<int>& visit){
        if(visit.count(idx))return;
        visit.insert(idx);
        for(int neighbor:m[idx]){
            if(!visit.count(neighbor)){
                dfs(neighbor, m, visit);
            }
        }
        
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> m;
        unordered_set<int> visit;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<n;i++){
            if(!visit.count(i)){
                ans = ans+1;
                dfs(i, m, visit);
            }
        }

        return ans;
    }
};
