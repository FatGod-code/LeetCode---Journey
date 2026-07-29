class Solution {
public:
    bool isPalindrome(string s)
    {
        std::string str;
        for (const auto c : s)
        {
            if (!std::isalpha(c) && !std::isdigit(c)) { continue; }
            str += std::tolower(c);
        }

        int left = 0;
        int right = str.size()-1;
        while (left<right)
        {
            if (str[left]!=str[right]) { return false; }
            
            ++left;
            --right;
        }

        return true;
    }
};