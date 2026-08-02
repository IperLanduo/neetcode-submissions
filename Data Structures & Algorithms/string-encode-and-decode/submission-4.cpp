class Solution {

public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for(const string &s:strs){         
            encoded_string += to_string(s.size()) + "#" + s; //格式: 字串長度+"#"+字串
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> decoded_strs;

        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){ //尋找"#"位置
                j++;
            }
            int length = stoi(s.substr(i, j-i)); //提取長度的數字(from i to j)

            string str = s.substr(j + 1, length); //根據#前的數字，抓取字串長度
            decoded_strs.push_back(str);

            i=j+1+length; //指針移到下個字串開頭
        }
        
        return decoded_strs;
    }
};
