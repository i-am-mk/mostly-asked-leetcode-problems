// https://leetcode.com/problems/design-twitter/
class Twitter {
private:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, set<int>> friends;
    int currTweets;

public:
    Twitter() {
        tweets.clear();
        friends.clear();
        currTweets=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({currTweets++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for(auto tweet: tweets[userId])
            pq.push(tweet);
        for(auto followeeId: friends[userId])
        {
            for(auto tweet: tweets[followeeId])
                pq.push(tweet);
        }

        vector<int> ans;
        int n = 0;
        while(!pq.empty() && n<10)
        {
            pair<int, int> recentPost = pq.top();
            pq.pop();
            ans.push_back(recentPost.second);
            n++;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            friends[followerId].erase(followeeId);
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