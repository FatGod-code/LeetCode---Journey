class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> substrings;

        std::vector<std::vector<int>> isPalindromeTable(s.size(), std::vector<int>(s.size(), -1));

        GeneratePalindrome(s, 0, isPalindromeTable, substrings, results);

        return results;
    }

    void GeneratePalindrome(const std::string& s, int startIdx, std::vector<std::vector<int>>& isPalindromeTable,
                            std::vector<std::string>& substrings, std::vector<std::vector<std::string>>& results)
    {
        if (startIdx>=s.size())
        {
            results.emplace_back(substrings);
            return;
        }

        for (int numChoose = 1; numChoose<=s.size(); ++numChoose)
        {
            if (startIdx+numChoose-1>=s.size()) { break; }

            if (!IsPalindrome(s, startIdx, startIdx+numChoose-1, isPalindromeTable)) { continue; }

            std::string str(s, startIdx, numChoose);
            substrings.emplace_back(str);

            GeneratePalindrome(s, startIdx+numChoose, isPalindromeTable, substrings, results);

            substrings.pop_back();
        }
    }

    bool IsPalindrome(const std::string& s, int start, int end,
                      std::vector<std::vector<int>>& isPalindromeTable)
    {
        int value = isPalindromeTable[start][end];
        if (value!=-1) { return static_cast<bool>(value); }

        while (start<end)
        {
            if (s[start]!=s[end])
            {
                isPalindromeTable[start][end] = 0;
                return false;
            }

            ++start;
            --end;
        }

        isPalindromeTable[start][end] = 1;
        return true;
    }
};