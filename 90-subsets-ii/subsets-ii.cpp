class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> results;
        std::vector<int> subset;

        GenerateSubsets(nums, 0, subset, results);
        return results;    
    }

    void GenerateSubsets(const std::vector<int>& nums, int idx,
                         std::vector<int>& subset, std::vector<std::vector<int>>& results)
    {
        if (idx==nums.size())
        {
            results.emplace_back(subset);
            return;
        }

        int value = nums[idx];
        subset.emplace_back(value);

        GenerateSubsets(nums, idx+1, subset, results);

        while (idx+1<nums.size() && nums[idx]==nums[idx+1]) { ++idx; }

        subset.pop_back();
        GenerateSubsets(nums, idx+1, subset, results);
    }
};