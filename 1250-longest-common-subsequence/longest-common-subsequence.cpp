class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        std::vector<int> table(text2.size()+1, 0);
        for (int idx1 = 0; idx1<text1.size(); ++idx1)
        {
            int previous = 0;
            for (int idx2 = 0; idx2<text2.size(); ++idx2)
            {
                int temp = table[idx2+1];
                if (text1[idx1]==text2[idx2]) { table[idx2+1] = previous+1; }
                else { table[idx2+1] = std::max(table[idx2+1], table[idx2]); }

                previous = temp;
            }
        }

        return table.back();
    }
};