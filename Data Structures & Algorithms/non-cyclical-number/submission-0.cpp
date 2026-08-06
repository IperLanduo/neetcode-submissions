class Solution {
public:
    bool isHappy(int n) {
        vector<bool>record(1010,false);
        while(n!=1){
            int tmp=0;
            string str = to_string(n);
            for(const char&c:str)tmp += (c-'0')*(c-'0');
            if(record[tmp])return false;
            record[tmp]=true;
            n = tmp;
        }
        return true;
    }
};
