class Solution {
public:
    bool isValid(string s)
    {
        std::unordered_map<char, char> table{{')', '('}, {']', '['}, {'}', '{'}};
        std::stack<char> sta;
        for (const auto ele : s)
        {
            if (ele=='(' || ele=='[' || ele=='{') { sta.emplace(ele); }
            else
            {
                if (sta.empty()) { return false; }
                else if (sta.top()!=table[ele]) { return false; }
                else { sta.pop(); }
            }
        }

        return sta.empty() ? true : false;
    }
};