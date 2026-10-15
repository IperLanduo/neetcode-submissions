class Solution {
public:
    
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};

    int dfs(vector<vector<int>>& grid, int x, int y){
        int n=grid.size();
        int m=grid[0].size();

        
        if(x<0||y<0||x>=n||y>=m)return 0;
        if(grid[x][y]==0)return 0;

        grid[x][y]=0;
        int current_area=1;

        for(int i=0;i<4;i++){
            current_area+=dfs(grid, x+dx[i], y+dy[i]);
        }

        return current_area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        int temp=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    temp=dfs(grid, i, j);
                    ans = max(ans ,temp);
                }
            }
        }
        return ans;
    }
};
