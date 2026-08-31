class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        std::unordered_map<char, int> table;

        int results = 0;

        int startIdx = 0;
        for (int idx = 0; idx<s.size(); ++idx)
        {
            if (table.find(s[idx])==table.end())
            {
                results = std::max(idx-startIdx+1, results);
                table[s[idx]] = idx;
            }
            else if (table[s[idx]]<startIdx)
            {
                results = std::max(idx-startIdx+1, results);
                table[s[idx]] = idx;
            }
            else
            {
                results = std::max(idx-startIdx-2, results);

                startIdx = table[s[idx]]+1;
                table[s[idx]] = idx;
            }
        }

        return results;
    }
};  