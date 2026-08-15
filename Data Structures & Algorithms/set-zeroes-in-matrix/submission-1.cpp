class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> dir_x={0,0,1,-1};
        vector<int> dir_y={1,-1,0,0};

        vector<bool> rowZero(n, false);
        vector<bool> colZero(m, false);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    rowZero[i] = true; 
                    colZero[j] = true;
                }
            }
        }

       for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(rowZero[i] || colZero[j]){
                    matrix[i][j] = 0;
                }
            }

        }


    }
};
