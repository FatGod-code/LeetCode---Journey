class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        std::vector<std::string> results;

        const std::vector<std::string> table{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        std::queue<std::pair<int, std::string>> que;
        que.push({0, {}});
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto [idx, str] = que.front();
                que.pop();

                if (idx==digits.size())
                {
                    results.emplace_back(str);
                    continue;
                }

                const auto& numStr = table[digits[idx]-'0'];
                for (const auto ele : numStr)
                {
                    que.push({idx+1, str+ele});
                }
            }
        }

        return results;
    }
};