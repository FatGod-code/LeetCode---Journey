class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::priority_queue<int> pq;
        for (const auto ele : nums)
        {
            pq.emplace(ele);
            if (pq.size()>nums.size()-k+1) { pq.pop(); }
        }

        return pq.top();
    }
};