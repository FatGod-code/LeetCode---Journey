class Solution {
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = static_cast<int>(s.size()-1);
        while (left<right)
        {
            while (left<right && !std::isalnum(s[left])) { ++left; }
            while (left<right && !std::isalnum(s[right])) { --right; }

            const auto leftChar = s[left] |= 0x20;
            const auto rightChar = s[right] |= 0x20;
            if (leftChar!=rightChar) { return false; }

            ++left;
            --right;
        }

        return true;
    }
};