class Solution {
public:
    int reverse(int x)
    {
        std::string str = std::to_string(x);
        for (int idx = 0; idx<str.size()/2; ++idx) { std::swap(str[idx], str[str.size()-1-idx]); }

        if (str.back()=='-')
        {
            str = '-'+str;
            str.resize(str.size()-1);
        }

        long long value = stoll(str);
        return value>INT_MAX || value<INT_MIN ? 0 : value;
    }
};