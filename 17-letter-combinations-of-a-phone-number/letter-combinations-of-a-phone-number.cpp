class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        std::vector<std::string> results;
        std::string combination;

        GenerateCombinations(digits, 0, combination, results);
        return results;
    }

    void GenerateCombinations(const std::string& digits, int idx,
                              std::string& combination, std::vector<std::string>& results)
    {
        if (idx==digits.size())
        {
            results.emplace_back(combination);
            return;
        }

        char d = digits[idx];
        const auto& str = NumToString(d);
        for (const auto ele : str)
        {
            combination += ele;
            GenerateCombinations(digits, idx+1, combination, results);

            combination.pop_back();
        }
    }

    const std::string NumToString(char digit)
    {
        switch (digit)
        {
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
            default: return "";
        }

        return "";
    }
};