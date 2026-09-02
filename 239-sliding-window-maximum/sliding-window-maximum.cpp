class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        std::vector<int> results;

        std::deque<int> dq;
        
        int left = 0;
        for (int right = 0; right<nums.size(); ++right)
        {
            while (dq.size() && nums[right]>=nums[dq.back()]) { dq.pop_back(); }
            dq.emplace_back(right);

            if (right-left+1>k)
            {
                ++left;
                if (dq.size() && dq.front()<left) { dq.pop_front(); }
            }

            if (right-left+1==k) { results.emplace_back(nums[dq.front()]); }
        }

        return results;
    }
};