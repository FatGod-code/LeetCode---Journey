class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
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

        subset.emplace_back(nums[idx]);
        GenerateSubsets(nums, idx+1, subset, results);

        subset.pop_back();
        GenerateSubsets(nums, idx+1, subset, results);
    }
};