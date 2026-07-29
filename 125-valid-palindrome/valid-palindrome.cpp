class Solution {
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = static_cast<int>(s.size()-1);
        while (left<right)
        {
            while (left<right && !std::isalpha(s[left]) && !std::isdigit(s[left])) { ++left; }
            while (left<right && !std::isalpha(s[right]) && !std::isdigit(s[right])) { --right; }

            const auto leftChar = std::tolower(s[left]);
            const auto rightChar = std::tolower(s[right]);
            if (leftChar!=rightChar) { return false; }

            ++left;
            --right;
        }

        return true;
    }
};