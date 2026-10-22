class Solution {
public:

    bool dfs(int course, vector<vector<int>> &adj, unordered_set<int>& path){
        if (path.count(course)) {
            return false;
        }
        if(adj[course].empty())return true;
        path.insert(course);

        for(int neighbor: adj[course]){
            if(!dfs(neighbor, adj, path))return false;
        }
        path.erase(course);
        adj[course].clear();

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(const auto& pre: prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }

        unordered_set<int> path;

        for(int i=0;i<numCourses; i++){
            if(!dfs(i,adj,path))return false;
        }
        
        return true;
    }
};
