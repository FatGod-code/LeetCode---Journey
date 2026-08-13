class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int number = 1 << nums.size();
        std::vector<std::vector<int>> results;
        results.reserve(number);

        
        for (int i = 0; i<number; ++i)
        {
            std::vector<int> subset;
            subset.reserve(nums.size());
            for (int shift = 0; shift<nums.size(); ++shift)
            {
                int mask = 1 << shift;
                if (i & mask) { subset.emplace_back(nums[shift]); }
            }

            results.emplace_back(std::move(subset));
        }

        return results;
    }
};