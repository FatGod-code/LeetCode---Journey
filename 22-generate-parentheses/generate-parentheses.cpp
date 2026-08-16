class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        std::vector<std::string> results;
        std::string parentheses;

        GenerateParenthesisCombinations(n, 0, 0, parentheses, results);
        return results;
    }

    void GenerateParenthesisCombinations(int n, int numLeft, int numRight, 
                                         std::string& parentheses, std::vector<std::string>& results)
    {
        if (n==numLeft && n==numRight)
        {
            results.emplace_back(parentheses);
            return;
        }

        if (numLeft<n)
        {
            parentheses += '(';
            GenerateParenthesisCombinations(n, numLeft+1, numRight, parentheses, results);

            parentheses.pop_back();
        }

        if (numRight<n && numRight<numLeft)
        {
            parentheses += ')';
            GenerateParenthesisCombinations(n, numLeft, numRight+1, parentheses, results);

            parentheses.pop_back();
        }
    }
};