class Solution {
public:

    bool dfs(int idx,int parent, unordered_map<int, vector<int>> m,unordered_set<int>& visit){
        if(visit.count(idx))return false;
        visit.insert(idx);
    
        for(int neighbor:m[idx]){
            if(neighbor==parent)continue;
            if(!dfs(neighbor, idx, m, visit))return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int> visit;
        if(!dfs(0,-1,m,visit))return false;
        if(visit.size()==n)return true;
        return false;
        
    }
};
