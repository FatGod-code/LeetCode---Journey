class Twitter {
public:
    using VectorIterPair = std::pair<std::vector<std::pair<int, int>>::const_reverse_iterator,
                                     std::vector<std::pair<int, int>>::const_reverse_iterator>;
    
    Twitter() : mTimeStamp(0), mNumSeenPosts(10) {}
    
    void postTweet(int userId, int tweetId)
    {
        mUsersPosts[userId].push_back({tweetId, mTimeStamp});
        ++mTimeStamp;
    }
    
    vector<int> getNewsFeed(int userId)
    {
        auto cmp = [](const VectorIterPair& a, const VectorIterPair& b)
        {
            return a.first->second<b.first->second;
        };

        std::vector<VectorIterPair> begins;
        begins.push_back({mUsersPosts[userId].crbegin(), mUsersPosts[userId].crend()});
        
        const auto& followers = mUsersFollowers[userId];
        for (const auto follower : followers)
        {
            const auto& posts = mUsersPosts[follower];
            begins.push_back({posts.crbegin(), posts.crend()});
        }

        std::priority_queue<VectorIterPair, std::vector<VectorIterPair>, decltype(cmp)> pq;
        for (const auto& begin : begins)
        {
            if (begin.first==begin.second) { continue; }
            pq.emplace(begin);
        }

        std::vector<int> newsFeeds;
        newsFeeds.reserve(10);
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            if (top.first==top.second) { continue; }

            newsFeeds.emplace_back(top.first->first);
            if (newsFeeds.size()==mNumSeenPosts) { return newsFeeds;}

            const auto& next = std::next(top.first);
            if (next!=top.second) { pq.push({next, top.second}); }
        }
        return newsFeeds;

        return {};
    }
    
    void follow(int followerId, int followeeId)
    {
        mUsersFollowers[followerId].emplace(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        auto& followers = mUsersFollowers[followerId];
        if (followers.find(followeeId)==followers.end()) { return; }

        followers.erase(followeeId);
    }

private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> mUsersPosts;
    std::unordered_map<int, std::unordered_set<int>> mUsersFollowers;

    int mTimeStamp{0};
    const int mNumSeenPosts{10};
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */