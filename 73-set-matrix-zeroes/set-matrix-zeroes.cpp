class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        
        bool firstRowHas0 = false;
        for (int col = 0; col<n; ++col)
        {
            if (matrix[0][col]==0)
            {
                firstRowHas0 = true;
                break;
            }
        }

        bool firstColHas0 = false;
        for (int row = 0; row<m; ++row)
        {
            if (matrix[row][0]==0)
            {
                firstColHas0 = true;
                break;
            }
        }

        for (int row = 1; row<m; ++row)
        {
            for (int col = 1; col<n; ++col)
            {
                if (matrix[row][col]==0)
                {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        for (int row = 1; row<m; ++row)
        {
            if (matrix[row][0]==0)
            {
                for (int col = 1; col<n; ++col) { matrix[row][col] = 0; }
            }
        }

        for (int col = 1; col<n; ++col)
        {
            if (matrix[0][col]==0)
            {
                for (int row = 1; row<m; ++row) { matrix[row][col] = 0; }
            }
        }

        if (firstRowHas0)
        {
            for (int col = 0; col<n; ++col) { matrix[0][col] = 0; }
        }

        if (firstColHas0)
        {
            for (int row = 0; row<m; ++row) { matrix[row][0] = 0; }
        }
    }
};