class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int left=0;
        unordered_set<char>window;
        for(int i=0;i<s.size();i++){
            while(window.count(s[i])){
                window.erase(s[left]);
                left++;
            }
            window.insert(s[i]);
            
            ans = max(ans, i-left+1);
            
        }
        return ans;
    }
};


//abcdbf