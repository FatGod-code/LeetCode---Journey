class Solution {
public:
    string longestPalindrome(string s)
    {
        std::vector<std::vector<bool>> table(s.size(), std::vector<bool>(s.size(), false));

        std::pair<int, int> str;
        for (int idx = 0; idx<s.size(); ++idx)
        {
            table[idx][idx] = true;
            str = {idx, idx};
        }

        for (int idx = 0; idx<s.size()-1; ++idx)
        {
            if (s[idx]==s[idx+1])
            {
                table[idx][idx+1] = true;
                str = {idx, idx+1};
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
                    str = {idx, idx+l-1};
                }
            }
        }

        return s.substr(str.first, str.second-str.first+1);
    }
};