class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int m = grid.size();
        int n = grid[0].size();

        // 階段一：把所有的寶箱 (0) 都先放進 Queue 裡
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }    
            }
        }
        
        // 階段二：開始多源 BFS (注意這裡已經離開了上面的 for 迴圈)
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k]; // 統一使用 k
                int ny = y + dy[k]; // 統一使用 k
                
                // 1. 檢查是否超出邊界
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                
                // 2. 檢查是否為水域 (-1) 或是已經被走過的陸地
                // 只有遇到 INF (2147483647) 才可以走
                if(grid[nx][ny] != 2147483647) continue;
                
                // 3. 更新步數，並把新位置加入 Queue 繼續下一層擴散
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
};