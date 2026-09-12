class Solution {
public:
    int countSubstrings(string s)
    {
        std::unordered_set<std::string> table;

        int results = 0;
        for (int l = 1; l<=s.size(); ++l)
        {
            for (int idx = 0; idx<s.size(); ++idx)
            {
                if (idx+l-1>=s.size()) { continue; }

                std::string substr = s.substr(idx, l);
                if (table.find(substr)!=table.end()) { ++results; }
                else
                {
                    if (!isPalindromic(substr)) { continue; }

                    ++results;
                    table.emplace(substr);
                }
            }
        }

        return results;
    }

    bool isPalindromic(const std::string& str)
    {
        for (int idx = 0; idx<str.size(); ++idx)
        {
            if (str[idx]!=str[str.size()-1-idx]) { return false; }
        }

        return true;
    }
};