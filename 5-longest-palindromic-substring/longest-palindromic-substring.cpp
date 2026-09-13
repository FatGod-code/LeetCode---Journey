class Solution {
public:
    string longestPalindrome(string s)
    {
        std::vector<std::vector<bool>> table(s.size(), std::vector<bool>(s.size(), false));

        std::string results;
        for (int idx = 0; idx<s.size(); ++idx)
        {
            table[idx][idx] = true;
            results = s[idx];
        }

        for (int idx = 0; idx<s.size()-1; ++idx)
        {
            if (s[idx]==s[idx+1])
            {
                table[idx][idx+1] = true;
                results = s.substr(idx, 2);
            }
        }

        for (int l = 3; l<=s.size(); ++l)
        {
            for (int idx = 0; idx<s.size(); ++idx)
            {
                if (idx+l-1>=s.size()) { break; }

                if (s[idx]==s[idx+l-1] && table[idx+1][idx+l-2])\
                {
                    table[idx][idx+l-1] = true;
                    results = s.substr(idx, l);
                }
            }
        }

        return results;
    }
};