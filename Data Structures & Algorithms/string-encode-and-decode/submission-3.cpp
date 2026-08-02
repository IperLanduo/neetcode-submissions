class Solution {

public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for(const string &s:strs){         
            encoded_string += to_string(s.size()) + "#" + s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> decoded_strs;

        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int length = stoi(s.substr(i, j-i));
            string str = s.substr(j + 1, length);
            decoded_strs.push_back(str);

            i=j+1+length;
        }
        
        return decoded_strs;
    }
};
