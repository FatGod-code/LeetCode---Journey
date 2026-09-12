class Solution {
public:
    int rob(vector<int>& nums)
    {
        int results = 0;
        int value1 = 0;
        int value2 = 0;
        for (int idx = 0; idx<nums.size(); ++idx)
        {
            results = std::max(value1+nums[idx], value2);
            value1 = value2;
            value2 = results;
        }

        return results;
    }
};