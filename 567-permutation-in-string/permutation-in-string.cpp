class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        std::vector<int> table1(26);
        for (const auto ele : s1) { ++table1[ele-'a']; }

        for (int idx = 0; idx<s2.size(); ++idx)
        {
            if (idx+s1.size()-1>=s2.size()) { return false; }

            std::vector<int> table2(26);
            for (int index = idx; index<idx+s1.size(); ++index) { ++table2[s2[index]-'a']; }

            if (table1==table2) { return true; }
        }

        return false;
    }
};