class Solution {
public:
    int uniquePaths(int m, int n)
    {
        int totalSteps = m+n-2;
        int k = std::min(m-1, n-1);

        long long results = 1;
        for (int i = 1; i<=k; ++i)
        {
            results = (results* ((totalSteps-k+i)))/i;
        }

        return results;
    }
};