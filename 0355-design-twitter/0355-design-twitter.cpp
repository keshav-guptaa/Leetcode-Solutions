class Twitter {
public:
    int ct;
    unordered_map<int, set<int>> fo;
    unordered_map<int, vector<pair<int, int>>> t;
    
    Twitter() {
        ct = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        t[userId].push_back({ct++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for(auto it = t[userId].begin(); it != t[userId].end(); it++){
            pq.push(*it);
        }
        for(auto it = fo[userId].begin(); it != fo[userId].end(); it++){
            auto user = *it;
            for(auto it1 = t[user].begin(); it1 != t[user].end(); it1++){
                pq.push(*it1);
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            if(ans.size() == 10) break;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) fo[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fo[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */