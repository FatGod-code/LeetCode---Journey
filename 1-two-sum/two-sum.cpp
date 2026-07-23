class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        //test leetcode sync
        std::unordered_map<int, int> indexTable;
        for (int idx = 0; idx<nums.size(); ++idx)
        {
            int value1 = nums[idx];
            int value2 = target-nums[idx];

            auto found = indexTable.find(value2);
            if (found!=indexTable.end()) { return {idx, found->second}; }

            indexTable.emplace(value1, idx);
        }

        return {};
    }
};