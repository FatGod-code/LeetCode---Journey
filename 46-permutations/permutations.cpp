class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<std::vector<int>> results;
        GeneratePermutations(nums, 0, results);

        return results;
    }

    void GeneratePermutations(std::vector<int>& nums, int startIdx, std::vector<std::vector<int>>& results)
    {
        if (startIdx==nums.size())
        {
            results.emplace_back(nums);
            return;
        }

        for (int idx = startIdx; idx<nums.size(); ++idx)
        {
            std::swap(nums[idx], nums[startIdx]);
            GeneratePermutations(nums, startIdx+1, results);
            
            std::swap(nums[idx], nums[startIdx]);
        }
    }
};