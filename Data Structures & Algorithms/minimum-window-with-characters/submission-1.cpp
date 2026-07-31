class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size())return "";
        
        int left=0;
        int right=0;
        
        int start=0;
        int minLen=INT_MAX;
        int form=t.size();
        
        unordered_map<char,int> need;

        for(int i=0;i<t.size();i++){
            need[t[i]]++;
        }

        while(right<s.size()){
            if(need[s[right]]>0){
                form--;
            }
            need[s[right]]--;
            while(form==0){
                if(right-left+1 < minLen){
                    minLen=right-left+1;
                    start=left;
                }
                
                need[s[left]]++;
                if(need[s[left]]>0){
                    form++;
                }
                left++;
            }
            right++;
        }
        return minLen==INT_MAX ? "" : s.substr(start,minLen);

    }
};
