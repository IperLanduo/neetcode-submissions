class Solution {
public:
    bool isValid(string s) {
        stack <char> vaild;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                vaild.push(s[i]);
                continue;
            }
            else{
                if (vaild.empty()) return false;
                
                if(s[i]==')' && vaild.top()=='(')vaild.pop();
                else if(s[i]=='}' && vaild.top()=='{')vaild.pop();
                else if(s[i]==']' && vaild.top()=='[')vaild.pop();
                else return false;
            }
        }
        if(!vaild.empty())return false;
        return true;
    }
};
