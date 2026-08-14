class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        reverse(matrix.begin(),matrix.end());

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

    }
};

/*

00 02
01 12
02 22
10 
11
12
20
21
22

*/
