class Solution {
public:
    
    int dir_x[4]={0,-1,1,0};
    int dir_y[4]={1,0,0,-1};

    bool dfs(vector<vector<char>>& board, string word,  int idx, int x, int y    ){
        if(idx==word.size()){
            return true;
        }  
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[idx]) {
            return false;
        }

        char temp = board[x][y];
        board[x][y] = '*';

        for(int i=0;i<4;i++){
            int now_x = x+dir_x[i];
            int now_y = y+dir_y[i];

            if(dfs(board, word, idx + 1, now_x, now_y)) return true;
        }
        board[x][y]=temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        string s = "";
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board, word, 0,i,j))return true;
            }
        }
        return false;
    }
};
