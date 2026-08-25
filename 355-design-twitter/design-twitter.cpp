class Twitter {
public:
    Twitter() : NUM_POSTS_SEEN(10) {}
    
    void postTweet(int userId, int tweetId)
    {
        mPosts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId)
    {
        std::unordered_set<int> filter = mUsersFollowers[userId];
        filter.emplace(userId);

        std::vector<int> newsFeeds;
        newsFeeds.reserve(NUM_POSTS_SEEN);
        
        for (auto critr = mPosts.crbegin(); critr!=mPosts.crend(); ++critr)
        {
            const auto user = critr->first;
            if (filter.find(user)==filter.end()) { continue; }

            newsFeeds.emplace_back(critr->second);
            if (newsFeeds.size()==NUM_POSTS_SEEN) { return newsFeeds; }
        }
        
        return newsFeeds;
    }
    
    void follow(int followerId, int followeeId)
    {
        mUsersFollowers[followerId].emplace(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        auto foundUser = mUsersFollowers.find(followerId);
        if (foundUser==mUsersFollowers.end()) { return; }

        auto& followers = foundUser->second;
        followers.erase(followeeId);
    }

private:
    std::list<std::pair<int, int>> mPosts;
    std::unordered_map<int, std::unordered_set<int>> mUsersFollowers;

    const int NUM_POSTS_SEEN{10};
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */