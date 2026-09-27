class Solution {
public:
    bool isMatch(string s, string p)
    {
        std::vector<bool> table(p.size()+1, false);
        table[0] = true;
        for (int idx = 0; idx<p.size(); ++idx)
        {
            if (p[idx]=='*') { table[idx+1] = table[idx-1]; }
        }

        for (int idx1 = 0; idx1<s.size(); ++idx1)
        {
            bool previous = table[0];
            table[0] = false;
            for (int idx2 = 0; idx2<p.size(); ++idx2)
            {
                bool temp = table[idx2+1];
                if (s[idx1]==p[idx2] || p[idx2]=='.') { table[idx2+1] = previous; }
                else if (p[idx2]=='*')
                {
                    table[idx2+1] = table[idx2-1];
                    if (s[idx1]==p[idx2-1] || p[idx2-1]=='.') { table[idx2+1] = table[idx2+1] || temp; }
                }
                else { table[idx2+1] = false; }

                previous = temp;
            }
        }

        return table.back();
    }
};