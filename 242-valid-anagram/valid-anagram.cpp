class Solution {
public:
    bool isAnagram(string s, string t)
    {
        std::vector<int> tableS(26, 0);
        for (int idx = 0; idx<s.size(); ++idx) { ++tableS[s[idx]-'a']; }

        std::vector<int> tableT(26, 0);
        for (int idx = 0; idx<t.size(); ++idx) { ++tableT[t[idx]-'a']; }

        if (tableS!=tableT) { return false; }
        return true;
    }
};