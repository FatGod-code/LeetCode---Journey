class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        std::vector<std::vector<int>> results;

        int number = std::pow(2, nums.size());
        for (int i = 0; i<number; ++i)
        {
            std::vector<int> subset;
            for (int shift = 0; shift<nums.size(); ++shift)
            {
                int mask = 1 << shift;
                if (i & mask) { subset.emplace_back(nums[shift]); }
            }

            results.emplace_back(subset);
        }

        return results;
    }
};