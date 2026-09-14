class Solution {
public:
    vector<vector<string>> ans;

    void back(vector<string>& tmp,vector<bool>& check, vector<bool>& diag1,vector<bool>& diag2, int idx){
        int n= tmp.size();

        if(idx==n){
            ans.push_back(tmp);
            return;
        }
        

        for(int i=0;i<n;i++){
            if(check[i]||diag1[idx-i+n-1]||diag2[idx+i]){
                continue;
            }
            tmp[idx][i]='Q';
            check[i]=true;
            diag1[idx-i+n-1]=true;
            diag2[idx+i]=true;

            back(tmp, check, diag1, diag2, idx+1);

            tmp[idx][i]='.';
            check[i]=false;
            diag1[idx-i+n-1]=false;
            diag2[idx+i]=false;
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> tmp(n,string(n,'.'));
        vector<bool> check(n,false);
        vector<bool> diag1(2 * n,false);
        vector<bool> diag2(2 * n,false);
        back(tmp, check, diag1, diag2, 0);
        return ans;
    }
};
