class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        std::vector<int> table(256, -1);

        int results = 0;

        int startIdx = 0;
        for (int idx = 0; idx<s.size(); ++idx)
        {
            int tidx = static_cast<int>(s[idx]);
            if (table[tidx]==-1 || table[tidx]<startIdx) { results = std::max(idx-startIdx+1, results); }
            else
            {
                results = std::max(idx-startIdx-2, results);
                startIdx = table[tidx]+1;

            }
            table[tidx] = idx;
        }

        return results;
    }
};  