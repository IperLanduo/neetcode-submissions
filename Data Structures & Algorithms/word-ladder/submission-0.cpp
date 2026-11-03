class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> m;
        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList[i].size();j++){
                string word = wordList[i];
                string temp = word;
                temp[j] = '*';
                m[temp].push_back(word);
            }
        }

        queue<pair<string, int> >q;
        set<string >record;
        pair<string,int > k = {beginWord, 1};
        
        q.push(k);
        record.insert(beginWord);
        
        while(!q.empty()){
            pair<string, int> tmp = q.front();
            q.pop();

            if(tmp.first==endWord){
                return tmp.second;
            }

            for(int i=0;i<tmp.first.size();i++){
                string check = tmp.first;
                check[i] = '*';
                for(const auto& same: m[check]){
                    if(!record.count(same)){
                        record.insert(same);
                        q.push({same, tmp.second+1});
                    }

                }
            }

        } 
        return 0;
    }
};
