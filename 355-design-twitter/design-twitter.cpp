class Twitter {
public:
    using ListPairConstIter = std::list<std::pair<int, int>>::const_iterator;
    using IterPair = std::pair<ListPairConstIter, ListPairConstIter>;

    Twitter() : NUM_POSTS_SEEN(10), mTimeStamp(0) {}
    
    void postTweet(int userId, int tweetId)
    {
        mUsersPosts[userId].emplace_front(std::pair<int, int>{mTimeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId)
    {
        auto cmp = [](const IterPair& a, const IterPair& b)
        {
            return a.first->first<b.first->first;
        };

        std::vector<IterPair> lists;
        lists.emplace_back(IterPair{mUsersPosts[userId].cbegin(), mUsersPosts[userId].cend()});
        
        for (const auto follower : mUsersFollowers[userId])
        {
            const auto& posts = mUsersPosts[follower];
            lists.emplace_back(IterPair{posts.cbegin(), posts.cend()});
        }

        std::priority_queue<IterPair, std::vector<IterPair>, decltype(cmp)> pq;
        for (const auto& itPair : lists)
        {
            if (itPair.first!=itPair.second) { pq.emplace(itPair); }
        }

        std::vector<int> newsFeeds;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            newsFeeds.emplace_back(top.first->second);
            if (newsFeeds.size()==NUM_POSTS_SEEN) { return newsFeeds; }

            auto next = std::next(top.first);
            if (next!=top.second) { pq.emplace(IterPair{next, top.second}); }
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
    std::unordered_map<int, std::list<std::pair<int, int>>> mUsersPosts;
    std::unordered_map<int, std::unordered_set<int>> mUsersFollowers;

    const int NUM_POSTS_SEEN{10};
    int mTimeStamp{0};
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */