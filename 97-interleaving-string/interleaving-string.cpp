class Solution {
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size()+s2.size()!=s3.size()) { return false; }

        std::vector<std::vector<unsigned int>> table(s1.size()+1, std::vector<unsigned int>(s2.size()+1, 0));
        table[0][0] = 1;
        for (int idx = 0; idx<s1.size(); ++idx)
        {
            if (s1[idx]!=s3[idx]) { table[idx+1][0] = 0; }
            else { table[idx+1][0] = table[idx][0]; }
        }

        for (int idx = 0; idx<s2.size(); ++idx)
        {
            if (s2[idx]!=s3[idx]) { table[0][idx+1] = 0; }
            else { table[0][idx+1] = table[0][idx]; }
        }

        for (int idx1 = 0; idx1<s1.size(); ++idx1)
        {
            for (int idx2 = 0; idx2<s2.size(); ++idx2)
            {
                if (s1[idx1]==s3[idx1+idx2+1]) { table[idx1+1][idx2+1] += table[idx1][idx2+1]; }
                if (s2[idx2]==s3[idx1+idx2+1]) { table[idx1+1][idx2+1] += table[idx1+1][idx2]; }
            }
        }

        return table.back().back()==0 ? false : true;
    }
};