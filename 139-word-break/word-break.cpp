class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());

        std::vector<bool> table(s.size()+1, false);
        table[0] = true;

        for (int i = 1; i<=s.size(); ++i)
        {
            for (int j = 0; j<i; ++j)
            {
                if (table[j] && wordSet.count(s.substr(j, i-j)))
                {
                    table[i] = true;
                }
            }
        }

        return table.back();
    }
};