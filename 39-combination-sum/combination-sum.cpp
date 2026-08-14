class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());

        std::vector<std::vector<int>> results;
        std::vector<int> combination;
        GenerateCombinations(candidates, target, 0, combination, results);

        return results;
    }

    void
    GenerateCombinations(const std::vector<int>& candidates, int target, int startIdx,
                         std::vector<int>& combination, std::vector<std::vector<int>>& results)
    {
        if (target==0)
        {
            results.emplace_back(combination);
            return;
        }

        if (target<0) { return; }

        for (int idx = startIdx; idx<candidates.size(); ++idx)
        {
            int value = candidates[idx];
            if (value>target) { break; }

            combination.emplace_back(value);
            
            GenerateCombinations(candidates, target-value, idx, combination, results);
            combination.pop_back();
        }
    }
};