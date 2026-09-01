class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int results = 0;

        std::vector<int> table(26);
        
        int left = 0;
        for (int right = 0; right<s.size(); ++right)
        {
            unsigned char rightIdx = s[right]-'A';
            ++table[rightIdx];

            while (Check(table, k))
            {
                unsigned char leftIdx = s[left]-'A';
                --table[leftIdx];
                ++left;
            }

            results = std::max(right-left+1, results);
        }

        return results;
    }

private:
    bool Check(const std::vector<int>& table, int k)
    {
        int numChars = 0;
        for (int idx = 0; idx<table.size(); ++idx) { numChars += table[idx]; }
        
        int maxValue = *(std::ranges::max_element(table));
        if (numChars-maxValue>k) { return true; }

        return false;
    }
};