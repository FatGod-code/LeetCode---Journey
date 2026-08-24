class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (const auto ele : nums)
        {
            pq.emplace(ele);
            if (pq.size()>k) { pq.pop(); }
        }

        return pq.top();
    }
};