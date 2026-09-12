class Solution {
public:
    int rob(vector<int>& nums)
    {
        int size = static_cast<int>(nums.size());

        int value1 = 0;
        int value2 = 0;
        int maxAmount1 = nums[0];
        for (int idx = 0; idx<size-1; ++idx)
        {
            maxAmount1 = std::max(value1+nums[idx], value2);
            value1 = value2;
            value2 = maxAmount1;
        }

        value1 = 0;
        value2 = 0;
        int maxAmount2 = 0;
        for (int idx = 1; idx<size; ++idx)
        {
            maxAmount2 = std::max(value1+nums[idx], value2);
            value1 = value2;
            value2 = maxAmount2;
        }

        int results = std::max(maxAmount1, maxAmount2);
        return results;
    }
};