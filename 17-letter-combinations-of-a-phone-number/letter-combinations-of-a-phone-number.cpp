class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size()==0) { return {}; }

        std::vector<std::string> results;

        std::vector<std::string> table{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        std::stack<std::string> sta;
        sta.emplace("");
        while (!sta.empty())
        {
            auto str = sta.top();
            sta.pop();

            if (str.size()==digits.size())
            {
                results.emplace_back(str);
                continue;
            }

            int idx = digits[str.size()]-'0';
            const auto& numStr = table[idx];
            for (const auto ele : numStr)
            {
                sta.emplace(str+ele);
            }
        }


        return results;
    }
};