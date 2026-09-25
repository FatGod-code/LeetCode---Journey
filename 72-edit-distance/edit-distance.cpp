class Solution {
public:
    int minDistance(string word1, string word2)
    {
        std::vector<std::vector<int>> table(word1.size()+1, std::vector<int>(word2.size()+1, 0));
        for (int idx = 1; idx<table.size(); ++idx) { table[idx][0] = table[idx-1][0]+1; }
        for (int idx = 1; idx<table[0].size(); ++idx) { table[0][idx] = table[0][idx-1]+1; }

        for (int idx1 = 0; idx1<word1.size(); ++idx1)
        {
            for (int idx2 = 0; idx2<word2.size(); ++idx2)
            {
                if (word1[idx1]==word2[idx2]) { table[idx1+1][idx2+1] = table[idx1][idx2]; }
                else { table[idx1+1][idx2+1] = std::min({table[idx1][idx2], table[idx1+1][idx2], table[idx1][idx2+1]})+1; }
            }
        }

        return table.back().back();
    }
};