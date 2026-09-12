class Solution {
public:
    vector<vector<string> >ans;
    bool ispalindrome(string s){
        if(s=="")return false;
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[(n-i-1)])return false;
        }
        return true;
    }

    void back(vector<string>& v, string s,int start){
        if(start >= s.size()){
            ans.push_back(v);
            return ;
        }

        for(int end=start; end<s.size();end++){
            string tmp=s.substr(start, end-start+1);
            if(!ispalindrome(tmp))continue;
            v.push_back(tmp);
            back(v, s, end+1);
            v.pop_back();
        }

    }

    vector<vector<string>> partition(string s) {
        vector<string> v;

        
        back(v, s, 0);
        
        return ans;
    }
};
