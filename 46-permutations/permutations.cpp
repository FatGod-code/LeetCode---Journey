class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<std::vector<int>> results;
        std::vector<int> permutation;
        
        std::unordered_set<int> table;
        GeneratePermutations(nums, table, permutation, results);

        return results;
    }

    void GeneratePermutations(const std::vector<int>& nums, std::unordered_set<int>& table,
                              std::vector<int>& permutation, std::vector<std::vector<int>>& results)
    {
        if (table.size()==nums.size())
        {
            results.emplace_back(permutation);
            return;
        }

        for (const auto ele : nums)
        {
            if (table.find(ele)!=table.end()) { continue; }

            table.emplace(ele);
            permutation.emplace_back(ele);
            GeneratePermutations(nums, table, permutation, results);

            table.erase(ele);
            permutation.pop_back();
        }
    }
};