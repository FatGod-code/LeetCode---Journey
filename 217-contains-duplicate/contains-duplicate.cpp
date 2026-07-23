class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        std::unordered_set<int> table;
        for (int idx = 0; idx<nums.size(); ++idx)
        {
            auto found = table.find(nums[idx]);
            if (found!=table.end()) { return true;}

            table.emplace(nums[idx]);
        }

        return false;
    }
};