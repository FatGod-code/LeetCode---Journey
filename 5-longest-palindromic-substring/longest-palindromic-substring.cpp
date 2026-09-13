class Solution {
public:
    string longestPalindrome(string s)
    {
        std::pair<int, int> results = {0, 0};
        for (int idx = 0; idx<s.size(); ++idx)
        {
            auto p1 = check(s, idx, idx);
            if (p1.second-p1.first+1>results.second-results.first+1) { results = p1; }

            auto p2 = check(s, idx, idx+1);
            if (p2.second-p2.first+1>results.second-results.first+1) { results = p2; }
        }

        return s.substr(results.first, results.second-results.first+1);
    }

    std::pair<int, int> check(const std::string& s, int left, int right)
    {
        while (left>=0 && right<s.size() && s[left]==s[right])
        {
            --left;
            ++right;
        }

        return {left+1, right-1};
    }
};