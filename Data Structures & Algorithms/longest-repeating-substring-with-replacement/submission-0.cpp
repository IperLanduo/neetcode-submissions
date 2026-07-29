class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int max_freq=0;
        int max_len=0;
        int temp=0;
        unordered_map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]+=1;
            max_freq=max(max_freq, m[s[i]]);
            if((i-left+1)-max_freq>k){
                m[s[left]]--;
                left++;
            }
            max_len=(i-left+1);
        }
        return max_len;
    }
};
