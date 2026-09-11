class Solution {
public:
    vector<string>ans;
    
    void back(string s, int n, int open, int close){
        if(s.size()==2*n){
            if(close==open)ans.push_back(s);
            return ;
        }
        if(open<close){
            return ;
        }

        back(s+'(', n, open+1, close);
        back(s+')', n, open, close+1);
        


    }

    vector<string> generateParenthesis(int n) {
        string s="";
        back(s, n, 0, 0);
        return ans;
    }
};
