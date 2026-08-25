class Twitter {
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId)
    {
        mPosts.emplace_front(userId, tweetId);
    }
    
    vector<int> getNewsFeed(int userId)
    {
        std::vector<int> feeds;
        auto &followees = mFollowees[userId];
        for (auto itr = mPosts.begin(); itr!=mPosts.end(); ++itr)
        {
            int posterId = itr->first;
            if (posterId==userId) feeds.emplace_back(itr->second);
            
            auto found = followees.find(posterId);
            if (found!=followees.end()) feeds.emplace_back(itr->second);
            
            if (feeds.size()==10) return feeds;
        }
        
        return feeds;
    }
    
    void follow(int followerId, int followeeId)
    {
        mFollowees[followerId].emplace(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        auto foundFollowee = mFollowees[followerId].find(followeeId);
        if (foundFollowee!=mFollowees[followerId].end()) foundFollowee = mFollowees[followerId].erase(foundFollowee);
    }
    
private:
    std::unordered_map<int, std::unordered_set<int>> mFollowees;
    std::list<std::pair<int, int>> mPosts;
};