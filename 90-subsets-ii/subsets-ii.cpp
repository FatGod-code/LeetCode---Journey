class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> results;
        std::vector<int> subset;

        for (int count = 0; count<=nums.size(); ++count)
        {
            GenerateSubsets(nums, count, 0, subset, results);
        }

        return results;
    }

    void GenerateSubsets(const std::vector<int>& nums, int count, int startIdx,
                         std::vector<int>& subset, std::vector<std::vector<int>>& results)
    {
        if (subset.size()==count)
        {
            results.emplace_back(subset);
            return;
        }

        for (int idx = startIdx; idx<nums.size(); ++idx)
        {
            int value = nums[idx];
            subset.emplace_back(value);

            GenerateSubsets(nums, count, idx+1, subset, results);

            subset.pop_back();

            while (idx+1<nums.size() && nums[idx]==nums[idx+1]) { ++idx; }
        }
    }
};