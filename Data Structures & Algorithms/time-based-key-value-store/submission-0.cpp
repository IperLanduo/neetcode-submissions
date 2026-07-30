class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> store;

    TimeMap() {    
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key)==store.end())return "";

        const vector<pair<int, string>> &arr = store[key];
        string ans="";
        int left=0;
        int right=arr.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(arr[mid].first<=timestamp){
                ans = arr[mid].second;
                left=mid+1;
            }
            else right = mid-1;

        }

        return ans;
    }
};
