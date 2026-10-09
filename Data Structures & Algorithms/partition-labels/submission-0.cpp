class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        map<char ,int>m;
        for(int i=0;i<s.size();i++)m[s[i]]=i;

        int end=0, tmp=0;
        for(int i=0;i<s.size();i++){
            tmp++;
            end = max(end, m[s[i]]);
            if(end==i){
                ans.push_back(tmp);
                end=-1;
                tmp=0;
            }
        }
        return ans;

    }
};
