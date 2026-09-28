class Solution {
public:
    int maxDepth(string s)
    {
        int numLeft = 0;
        int results = 0;
        for (const auto ele : s)
        {
            if (ele!='(' && ele!=')') { continue; }
            
            if (ele=='(')
            {
                ++numLeft;
                results = std::max(numLeft, results);
            }
            else { --numLeft; }
        }

        return results;
    }
};