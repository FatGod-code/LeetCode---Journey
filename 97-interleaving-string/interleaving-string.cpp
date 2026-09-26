class Solution {
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size()+s2.size()!=s3.size()) { return false; }

        std::vector<bool> table(s2.size()+1, false);
        table[0] = true;
        for (int idx = 0; idx<s2.size(); ++idx)
        {
            if (s2[idx]==s3[idx]) { table[idx+1] = table[idx]; }
            else  { table[idx+1] = false; }
        }

        for (int idx1 = 0; idx1<s1.size(); ++idx1)
        {
            table[0] = s1[idx1]==s3[idx1] ? table[0] : false;
            for (int idx2 = 0; idx2<s2.size(); ++idx2)
            {
                bool previous = table[idx2+1];
                table[idx2+1] = false;
                
                if (s1[idx1]==s3[idx1+idx2+1]) { table[idx2+1] = table[idx2+1] || previous; }
                if (s2[idx2]==s3[idx1+idx2+1]) { table[idx2+1] = table[idx2+1] || table[idx2]; }
            }
        }

        return table.back();
    }
};