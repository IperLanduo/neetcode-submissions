class Solution {
public:
    vector<int> ans;
    bool dfs(int idx, vector<vector<int>>& adj, vector<int>& visit){
        if(visit[idx]==1)return false;
        if(visit[idx]==2)return true;

        visit[idx]=1;

        for(int neighbor:adj[idx]){
            if(!dfs(neighbor, adj, visit))return false;
        }

        visit[idx]=2;
        ans.push_back(idx);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(const auto& pre:prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }
        vector<int> visit(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(visit[i]==0){
    if(!dfs(i,adj,visit))return {};
                    }
                            }
        return ans;
    }
};
