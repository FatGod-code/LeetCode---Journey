class Solution {
public:
    string longestPalindrome(string s)
    {
        std::vector<bool> table(s.size(), false);

        std::pair<int, int> str = {0, 0};
        for (int i = s.size()-1; i>=0; --i)
        {
            for (int j = s.size()-1; j>=i; --j)
            {
                if (s[i]==s[j] && (j-i<=1 || table[j-1]))
                {
                    table[j] = true;
                    if (j-i+1>str.second-str.first+1) { str = {i, j}; }
                }
                else { table[j] = false; }
            }
        }

        return s.substr(str.first, str.second-str.first+1);
    }
};