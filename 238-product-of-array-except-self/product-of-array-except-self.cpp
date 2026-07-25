class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        std::vector<int> results(nums.size(), 1);
        int value = 1;
        for (int idx = 1; idx<nums.size(); ++idx)
        {
            value *= nums[idx-1];
            results[idx] = value;
        }

        value = 1;
        for (int idx = nums.size()-2; idx>=0; --idx)
        {
            value *= nums[idx+1];
            results[idx] *= value;
        }
        
        return results;
    }
};