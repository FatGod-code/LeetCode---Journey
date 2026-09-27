class Solution {
public:
    int numDistinct(string s, string t)
    {
        std::vector<std::vector<unsigned>> table(s.size()+1, std::vector<unsigned>(t.size()+1, 0));
        table[0][0] = 1;
        for (int idx = 0; idx<s.size(); ++idx) { table[idx+1][0] = 1; }
        for (int idx = 0; idx<t.size(); ++idx) { table[0][idx+1] = 0; }

        for (int idx1 = 0; idx1<s.size(); ++idx1)
        {
            for (int idx2 = 0; idx2<t.size(); ++idx2)
            {
                if (s[idx1]==t[idx2]) { table[idx1+1][idx2+1] = table[idx1][idx2]+table[idx1][idx2+1]; }
                else { table[idx1+1][idx2+1] = table[idx1][idx2+1]; }
            }
        }

        return table.back().back();
    }
};