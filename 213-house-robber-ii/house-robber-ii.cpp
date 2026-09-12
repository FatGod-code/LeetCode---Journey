class Solution {
public:
    int rob(vector<int>& nums)
    {
        if (nums.size()==1) { return nums[0]; }

        int size = static_cast<int>(nums.size());
        
        int value1 = dp(nums, 0, size-1);
        int value2 = dp(nums, 1, size);
        
        return std::max(value1, value2);
    }

    int dp(const std::vector<int>& nums, int start, int end)
    {
        int value1 = 0;
        int value2 = 0;
        int maxAmount = 0;
        for (int idx = start; idx<end; ++idx)
        {
            maxAmount = std::max(value1+nums[idx], value2);
            value1 = value2;
            value2 = maxAmount;
        }

        return maxAmount;
    }
};