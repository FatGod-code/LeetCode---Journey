class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        std::vector<std::vector<int>> table(text1.size()+1, std::vector<int>(text2.size()+1, 0));
        for (int idx1 = 0; idx1<text1.size(); ++idx1)
        {
            for (int idx2 = 0; idx2<text2.size(); ++idx2)
            {
                if (text1[idx1]==text2[idx2]) { table[idx1+1][idx2+1] = table[idx1][idx2]+1; }
                else { table[idx1+1][idx2+1] = std::max(table[idx1][idx2+1], table[idx1+1][idx2]); }
            }
        }

        return table.back().back();
    }
};