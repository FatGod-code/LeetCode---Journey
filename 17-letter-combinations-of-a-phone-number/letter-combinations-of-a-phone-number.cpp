class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size()==0) { return {}; } 

        std::vector<std::string> results;

        const std::vector<std::string> table{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        std::queue<std::string> que;
        que.push({});
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto str = std::move(que.front());
                que.pop();

                if (str.size()==digits.size())
                {
                    results.emplace_back(str);
                    continue;
                }

                const auto& numStr = table[digits[str.size()]-'0'];
                for (const auto ele : numStr) { que.push(str+ele); }
            }
        }

        return results;
    }
};