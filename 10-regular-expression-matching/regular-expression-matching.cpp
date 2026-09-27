class Solution {
public:
    bool isMatch(string s, string p)
    {
        std::vector<std::vector<bool>> table(s.size()+1, std::vector<bool>(p.size()+1, false));
        table[0][0] = true;
        for (int idx = 0; idx<p.size(); ++idx)
        {
            if (p[idx]=='*') { table[0][idx+1] = table[0][idx+1] || table[0][idx-1]; }
        }

        for (int idx1 = 0; idx1<s.size(); ++idx1)
        {
            for (int idx2 = 0; idx2<p.size(); ++idx2)
            {
                if (s[idx1]==p[idx2] || p[idx2]=='.') { table[idx1+1][idx2+1] = table[idx1+1][idx2+1] || table[idx1][idx2]; }
                else if (p[idx2]=='*')
                {
                    table[idx1+1][idx2+1] = table[idx1+1][idx2+1] || table[idx1+1][idx2-1];
                    if (p[idx2-1]==s[idx1] || p[idx2-1]=='.') { table[idx1+1][idx2+1] = table[idx1+1][idx2+1] || table[idx1][idx2+1]; }
                }
            }
        }

        return table.back().back();
    }
};