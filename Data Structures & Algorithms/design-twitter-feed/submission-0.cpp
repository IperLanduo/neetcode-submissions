class Twitter {
public:
    int time=0;
    map<int,unordered_set<int>>followMap;
    unordered_map<int, vector<pair<int, int>>> tweets;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;

        followMap[userId].insert(userId);
        for(int followedId: followMap[userId]){
            auto& userTweets = tweets[followedId];
            int count=0;
            for(int i=userTweets.size()-1;i>=0;i--){
                maxHeap.push(userTweets[i]);
            }
        }

        followMap[userId].erase(userId);

        vector<int> result;
        while(!maxHeap.empty()&&result.size()<10){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
