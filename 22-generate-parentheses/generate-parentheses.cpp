class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        std::vector<std::string> results;
        std::string str;
        solve(n, 0, 0, str, results);

        return results;
    }

    void solve(int n, int left, int right, std::string& str, std::vector<std::string>& results)
    {
        if (n==left && n==right)
        {
            results.emplace_back(str);
            return;
        }

        if (left<n)
        {
            str += '(';
            solve(n, left+1, right, str, results);
            str.pop_back();
        }

        if (right<left)
        {
            str += ')';
            solve(n, left, right+1, str, results);
            str.pop_back();
        }
    }
};