class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<std::vector<int>> results;
        std::vector<int> permutation;
        
        std::vector<bool> table(nums.size(), false);
        GeneratePermutations(nums, table, permutation, results);

        return results;
    }

    void GeneratePermutations(const std::vector<int>& nums, std::vector<bool>& table,
                              std::vector<int>& permutation, std::vector<std::vector<int>>& results)
    {
        if (permutation.size()==nums.size())
        {
            results.emplace_back(permutation);
            return;
        }

        for (int idx = 0; idx<nums.size(); ++idx)
        {
            if (table[idx]) { continue; }

            table[idx] = true;
            permutation.emplace_back(nums[idx]);
            GeneratePermutations(nums, table, permutation, results);

            table[idx] = false;
            permutation.pop_back();
        }
    }
};