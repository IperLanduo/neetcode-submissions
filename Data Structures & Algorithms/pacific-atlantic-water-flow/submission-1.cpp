class Solution {
public:
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& mp, int x, int y, int num){
        int m=h.size();
        int n=h[0].size();

        if(x<0||y<0||x>=m||y>=n||mp[x][y]==true||h[x][y]<num)return ;

        mp[x][y]=true;
        dfs(h, mp, x+1, y, h[x][y]);
        dfs(h, mp, x-1, y, h[x][y]);
        dfs(h, mp, x, y+1, h[x][y]);
        dfs(h, mp, x, y-1, h[x][y]);
      
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool> > pacif(m,vector<bool>(n,false));
        vector<vector<bool> > atlan(m,vector<bool>(n,false));
        vector<vector<int> > ans;

        for(int i=0;i<n;i++){
            dfs(heights, pacif, 0, i, heights[0][i]);
            dfs(heights, atlan, m-1, i, heights[m-1][i]);
        }
        for(int i=0;i<m;i++){
            dfs(heights, pacif, i, 0, heights[i][0]);
            dfs(heights, atlan, i, n-1, heights[i][n-1]);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacif[i][j]&&atlan[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

    }
};
