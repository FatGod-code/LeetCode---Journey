class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        std::vector<int> product(nums.size(), 1);
        for (int idx = 1; idx<nums.size(); ++idx)
        {
            product[idx] = nums[idx-1]*product[idx-1];
        }

        std::vector<int> results(nums.size(), 1);
        for (int idx = nums.size()-2; idx>=0; --idx)
        {
            results[idx] = nums[idx+1]*results[idx+1];
        }

        for (int idx = 0; idx<results.size(); ++idx)
        {
            results[idx] = results[idx]*product[idx];
        }

        return results;
    }
};