// https://leetcode.com/problems/design-twitter/
class Twitter {
public:
    map<int, set<int>> friends;
    priority_queue<vector<int>> pq;
    int curr;

    Twitter() {
        friends.clear();
        pq = priority_queue<vector<int>>();
        curr=0;
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({curr++, userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<vector<int>> timelines = pq;
        int n = 0;
        while(!timelines.empty() && n<10)
        {
            vector<int> top = timelines.top();
            timelines.pop();
            if(top[1]==userId || friends[userId].count(top[1]))
            {
                ans.push_back(top[2]);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
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