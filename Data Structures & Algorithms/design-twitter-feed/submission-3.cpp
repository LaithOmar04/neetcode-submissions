class Twitter {
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> userTweets;
    int count = 0;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({count, tweetId});
        ++count;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;

        for(auto& tweet : userTweets[userId]) {
            maxHeap.push(tweet);
        }

        for(auto& id : follows[userId]) {
            for(auto& tweet : userTweets[id]) {
                maxHeap.push(tweet);
            }
        }

        vector<int> feed;
        for(int i = 0; i < 10; ++i) {
            if(maxHeap.empty()) break;

            feed.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
