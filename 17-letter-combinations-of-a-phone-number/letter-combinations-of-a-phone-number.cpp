class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size()==0) { return {}; }

        std::vector<std::string> results;
        std::string combination;

        const std::vector<std::string> table{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        GenerateCombinations(digits, 0, table, combination, results);
        return results;
    }

    void GenerateCombinations(const std::string& digits, int idx, const std::vector<std::string>& table,
                              std::string& combination, std::vector<std::string>& results)
    {
        if (idx==digits.size())
        {
            results.emplace_back(combination);
            return;
        }

        int tableIdx = digits[idx]-'0';
        const auto& str = table[tableIdx];
        for (const auto ele : str)
        {
            combination += ele;
            GenerateCombinations(digits, idx+1, table, combination, results);

            combination.pop_back();
        }
    }
};