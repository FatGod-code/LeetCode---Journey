class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int results = INT_MIN;

        std::pair<int, int> table = {1, 1};
        for (int idx = 0; idx<nums.size(); ++idx)
        {
            int value1 = table.first;
            int value2 = table.second;

            table.first = std::max({nums[idx], nums[idx]*value1, nums[idx]*value2});
            table.second = std::min({nums[idx], nums[idx]*value1, nums[idx]*value2});

            results = std::max(table.first, results);
        }

        return results;
    }
};