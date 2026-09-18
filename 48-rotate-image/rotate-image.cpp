class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int times = matrix.size()/2;
        for (int t = 0; t<times; ++t)
        {
            for (int idx = t; idx<matrix.size()-1-t; ++idx)
            {
                std::swap(matrix[t][idx], matrix[idx][matrix.size()-1-t]);
                std::swap(matrix[t][idx], matrix[matrix.size()-1-t][matrix.size()-1-idx]);
                std::swap(matrix[t][idx], matrix[matrix.size()-1-idx][t]);
            }
        }
    }
};
