class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.size()!=t.size()) { return false; }

        std::vector<int> table(26, 0);
        for (int idx = 0; idx<s.size(); ++idx) { ++table[s[idx]-'a']; }

        std::vector<int> tableT(26, 0);
        for (int idx = 0; idx<t.size(); ++idx) { --table[t[idx]-'a']; }

        for (auto ele : table)
        {
            if (ele) { return false; }
        }
        
        return true;
    }
};