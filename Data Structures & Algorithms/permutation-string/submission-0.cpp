class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        int n=s1.size();
        vector<int> v(26,0);     
        vector<int> v2(26,0);
        for(int i=0;i<s1.size();i++){
            v[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }

        if(v==v2)return true;

        for(int i=n;i<s2.size();i++){
            v2[s2[i]-'a']++;
            v2[s2[i-n]-'a']--;
            if(v==v2)return true;
        }
        return false;
    

    }
};
