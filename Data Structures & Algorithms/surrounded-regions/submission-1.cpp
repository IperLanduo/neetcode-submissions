class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y){
        int n=board.size();
        int m=board[0].size();
        if(x<0||y<0||x>=n||y>=m)return ;
        if(board[x][y]!='O')return;
        board[x][y]='T';
        dfs(board, x+1, y);
        dfs(board, x-1, y);
        dfs(board, x, y-1);
        dfs(board, x, y+1);


    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();


        for(int j=0;j<m;j++){
            if(board[0][j]=='O')dfs(board, 0, j);
            if(board[n-1][j]=='O')dfs(board, n-1, j);
        }

        for(int i=0;i<n;i++){
            if(board[i][0]=='O')dfs(board, i, 0);
            if(board[i][m-1]=='O')dfs(board, i, m-1);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }

    }
};
