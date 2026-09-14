class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int sum = nums.size()*(nums.size()+1)/2;
        for (int idx = 0; idx<nums.size(); ++idx)
        {
            sum -= nums[idx];
        }

        return sum;
    }
};