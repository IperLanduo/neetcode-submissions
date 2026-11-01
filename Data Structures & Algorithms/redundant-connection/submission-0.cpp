class Solution {
public:
    
    int find(int i, vector<int>& parent){
        if(parent[i]==i)return i;
        return parent[i]=find(parent[i],parent);
    }
    
    bool unite(int i, int j, vector<int>& parent, vector<int>& rank){
        int root_i = find(i, parent);
        int root_j = find(j, parent);

        if(root_i != root_j){
            if(rank[root_i]<rank[root_j]){
                parent[root_i] = root_j;
            }
            else if(rank[root_i]>rank[root_j]){
                parent[root_j] = root_i;
            }
            else {
                parent[root_j]=root_i;
                rank[root_i]++;
            }
            return true;
        }
        return false;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1,0);
        vector<int> rank(n+1,0);
        for(int i=1;i<=n;i++)parent[i]=i;
        for(auto& edge: edges){
            if(!unite(edge[0], edge[1],parent, rank)){
                return edge;
            }
        }
        return {};
    }
};
