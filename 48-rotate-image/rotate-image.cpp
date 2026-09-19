class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = static_cast<int>(matrix.size());

        int times = n/2;
        for (int t = 0; t<times; ++t)
        {
            for (int idx = t; idx<n-1-t; ++idx)
            {
                std::swap(matrix[t][idx], matrix[idx][n-1-t]);
                std::swap(matrix[t][idx], matrix[n-1-t][n-1-idx]);
                std::swap(matrix[t][idx], matrix[n-1-idx][t]);
            }
        }
    }
};
