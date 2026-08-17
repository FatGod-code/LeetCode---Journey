class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        std::vector<std::vector<std::string>> results;
        
        std::stack<std::pair<int, std::vector<std::string>>> sta;
        sta.push({0, {}});
        while (!sta.empty())
        {
            auto [idx, substrings] = sta.top();
            sta.pop();

            if (idx>=s.size())
            {
                results.emplace_back(substrings);
                continue;
            }

            for (int numChoose = 1; numChoose<=s.size(); ++numChoose)
            {
                if (idx+numChoose-1>=s.size()) { break; }

                if (!IsPalindrome(s, idx, idx+numChoose-1)) { continue; }

                std::string str(s, idx, numChoose);
                substrings.emplace_back(str);
                sta.push({idx+numChoose, substrings});

                substrings.pop_back();
            }
        }

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
        
            auto isPalindrome = IsPalindrome(s, startIdx, startIdx+numChoose-1);
            if (!isPalindrome) { continue; }

            std::string str(s, startIdx, numChoose);
            substrings.emplace_back(str);
            GeneratePartition(s, startIdx+numChoose, substrings, results);

            substrings.pop_back();
        }
    }

    bool IsPalindrome(const std::string& s, int start, int end)
    {
        while (start<end)
        {
            if (s[start]!=s[end]) { return false; }

            ++start;
            --end;
        }

        return true;
    }
};