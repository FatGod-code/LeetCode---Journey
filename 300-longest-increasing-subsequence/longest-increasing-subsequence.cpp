class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int results = 0;

        std::vector<int> table(nums.size(), 0);
        for (int idx = 0; idx<nums.size(); ++idx)
        {
            int numSequence = 1;
            for (int i = 0; i<idx; ++i)
            {
                if (nums[idx]>nums[i])
                {
                    numSequence = std::max(table[i]+1, numSequence);
                }
            }

            table[idx] = numSequence;
            results = std::max(table[idx], results);
        }

        return results;
    }
};