class Solution {
public:
    int rob(vector<int>& nums)
    {
        if (nums.size()==0) { return 0; }
        if (nums.size()==1) { return nums[0]; }
        if (nums.size()==2) { return std::max(nums[0], nums[1]); }

        std::vector<int> table(nums.size());
        table[0] = nums[0];
        table[1] = std::max(nums[0], nums[1]);
        for (int idx = 2; idx<nums.size(); ++idx)
        {
            table[idx] = std::max(table[idx-2]+nums[idx], table[idx-1]);
        }

        return table.back();
    }
};