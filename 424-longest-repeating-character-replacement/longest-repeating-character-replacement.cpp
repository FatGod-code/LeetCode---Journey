class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int results = 0;

        int maxFreq = 0;
        std::vector<int> table(26);

        int left = 0;
        for (int right = 0; right<s.size(); ++right)
        {
            unsigned char c = s[right]-'A';
            ++table[c];
            
            maxFreq = std::max(table[c], maxFreq);
            while (right-left+1-maxFreq>k)
            {
                unsigned char leftC = s[left]-'A';
                --table[leftC];
                ++left;
            }

            results = std::max(right-left+1, results);
        }

        return results;
    }
};