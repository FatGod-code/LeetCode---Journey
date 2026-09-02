class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int results = 0;

        std::vector<int> table(26);

        int left = 0;
        for (int right = 0; right<s.size(); ++right)
        {
            unsigned char c = s[right]-'A';
            ++table[c];

            while (check(table, k))
            {
                unsigned char leftC = s[left]-'A';
                --table[leftC];
                
                ++left;
            }

            results = std::max(right-left+1, results);
        }

        return results;
    }

private:
    bool check(const std::vector<int>& table, int k)
    {
        int numChars = 0;
        for (const auto ele : table) { numChars += ele; }

        int maxValue = *(std::ranges::max_element(table));
        numChars -= maxValue;

        return numChars>k ? true : false;
    }
};