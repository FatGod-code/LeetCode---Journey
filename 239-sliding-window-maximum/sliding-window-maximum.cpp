class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        std::vector<int> results;

        std::priority_queue<std::pair<int, int>> pq;

        int left = 0;
        for (int right = 0; right<nums.size(); ++right)
        {
            pq.push({nums[right], right});

            if (right-left+1>k)
            {
                ++left;
                while (pq.size() && pq.top().second<left) { pq.pop(); }
            }

            if (right-left+1==k) { results.emplace_back(pq.top().first); }
        }


        return results;
    }
};