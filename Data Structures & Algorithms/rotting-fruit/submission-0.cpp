class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int> >q;
        int n=grid.size();
        int m=grid[0].size();
        int min=0;
        int fresh_count=0;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)fresh_count++;
            }
        }

        while(!q.empty()&&fresh_count>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                for(int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];

                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        fresh_count--;
                        q.push({nx,ny});
                    }
                }
            }
            min++;
        }
        if(fresh_count!=0)return -1;
        else return min;

    }
};
