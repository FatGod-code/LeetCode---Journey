class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int results = 0;

        std::vector<int> table(nums.size(), 1);
        for (int idx = 0; idx<nums.size(); ++idx)
        {
            for (int i = 0; i<idx; ++i)
            {
                if (nums[idx]>nums[i]) { table[idx] = std::max(table[i]+1, table[idx]); }
            }

            results = std::max(table[idx], results);
        }

        return results;
    }
};