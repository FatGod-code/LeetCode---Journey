class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int value = 0;
        for (int i = 0; i<=nums.size(); ++i) { value ^= i; }
        for (int idx = 0;idx<nums.size(); ++idx) { value ^= nums[idx]; }

        return value;
    }
};