class Solution {
public:
vector<string>ans;
vector<string > phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void back(string digits, string s, int idx){
        if(idx==digits.size()){
            ans.push_back(s);
            return;
        }
        int digit = digits[idx]-'0';
        string letters = phone[digit];
        for(int i=0;i<letters.size();i++){
            back(digits, s+letters[i], idx+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits=="")return ans;
        back(digits, "", 0);
        return ans; 
    }
};
