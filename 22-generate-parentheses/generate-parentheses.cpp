class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        struct Frame
        {
            int numLeft{0};
            int numRigth{0};
            std::string parentheses;
        };

        std::vector<std::string> results;

        std::stack<Frame> sta;
        sta.emplace(0, 0, "");
        while (!sta.empty())
        {
            auto [left, right, p] = sta.top();
            sta.pop();

            if (left==n && right==n)
            {
                results.emplace_back(p);
                continue;
            }

            if (left<n)
            {
                p += '(';
                sta.emplace(left+1, right, p);

                p.pop_back();
            }

            if (right<n && right<left)
            {
                p += ')';
                sta.emplace(left, right+1, p);
                
                p.pop_back();
            }
        }

        return results;
    }
};