class Solution {
public:
    int minDistance(string word1, string word2)
    {
        std::vector<int> table(word2.size()+1, 0);
        for (int idx = 1; idx<table.size(); ++idx) { table[idx] = table[idx-1]+1; }

        for (int idx1 = 0; idx1<word1.size(); ++idx1)
        {
            int previous = idx1;//table[0];
            for (int idx2 = 0; idx2<word2.size(); ++idx2)
            {
                int temp = table[idx2+1];
                if (word1[idx1]==word2[idx2]) { table[idx2+1] = previous; }
                else { table[idx2+1] = std::min({table[idx2], table[idx2+1], previous})+1; }

                previous = temp;
            }
            ++table[0];
        }

        return table.back();
    }
};