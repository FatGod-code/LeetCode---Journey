class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> substrings;
        GeneratePartition(s, 0, substrings, results);
        
        return results;
    }

    void GeneratePartition(const std::string& s, int startIdx,
                           std::vector<std::string>& substrings, std::vector<std::vector<std::string>> &results)
    {
        if (startIdx>=s.size())
        {
            results.emplace_back(substrings);
            return;
        }

        for (int numChoose = 1; numChoose<=s.size(); ++numChoose)
        {
            if (startIdx+numChoose-1>=s.size()) { break; }
            
            std::string str(s, startIdx, numChoose);
            auto isPalindrome = IsPalindrome(str);

            if (!isPalindrome) { continue; }

            substrings.emplace_back(str);
            GeneratePartition(s, startIdx+numChoose, substrings, results);

            substrings.pop_back();
        }
    }

    bool IsPalindrome(const std::string& s)
    {
        for (int idx = 0; idx<s.size()/2; ++idx)
        {
            if (s[idx]!=s[s.size()-1-idx]) { return false; }
        }

        return true;
    }
};