class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        std::vector<std::vector<int>>results;
        std::vector<int> subset;
        for (int numEle = 0; numEle<=nums.size(); ++numEle)
        {
            GenerateSubsets(nums, numEle, 0, subset, results);
        }

        return results;
    }

    void GenerateSubsets(std::vector<int>& nums, int numEle, int startIdx,
                         std::vector<int> subset, std::vector<std::vector<int>>& results)
    {
        if (numEle==0)
        {
            results.emplace_back(subset);
            return;
        }

        for (int idx = startIdx; idx<nums.size(); ++idx)
        {
            subset.emplace_back(nums[idx]);
            GenerateSubsets(nums, numEle-1, idx+1, subset, results);
            subset.pop_back();
        }

    }
};