class LRUCache {
private:
    int n;
    list<pair<int,int>> lrulist;
    unordered_map<int ,list<pair<int,int>>::iterator>m;
public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())return -1;
        lrulist.splice(lrulist.begin(),lrulist,m[key]);
        return m[key]->second;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){ //already exist
            m[key]->second = value;
            lrulist.splice(lrulist.begin(), lrulist, m[key]);
            return ;
        }

        if(m.size()==n){
            int lrukey = lrulist.back().first;
            lrulist.pop_back();
            m.erase(lrukey);
        }
        
        lrulist.push_front({key,value});
        m[key] = lrulist.begin();
    }
};
