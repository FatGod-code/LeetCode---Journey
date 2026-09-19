class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        bool firstRowHas0 = false;
        for (int idx = 0; idx<matrix.size(); ++idx)
        {
            if (matrix[idx][0]==0)
            {
                firstRowHas0 = true;
                break;
            }
        }

        bool firstColHas0 = false;
        for (int idx = 0; idx<matrix[0].size(); ++idx)
        {
            if (matrix[0][idx]==0)
            {
                firstColHas0 = true;
                break;
            }
        }

        for (int row = 1; row<matrix.size(); ++row)
        {
            for (int col = 1; col<matrix[0].size(); ++col)
            {
                if (matrix[row][col]==0)
                {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        for (int row = 1; row<matrix.size(); ++row)
        {
            if (matrix[row][0]==0)
            {
                for (int col = 1; col<matrix[0].size(); ++col) { matrix[row][col] = 0; }
            }
        }

        for (int col = 1; col<matrix[0].size(); ++col)
        {
            if (matrix[0][col]==0)
            {
                for (int row = 1; row<matrix.size(); ++row) { matrix[row][col] = 0; }
            }
        }

        if (firstRowHas0)
        {
            for (int row = 0; row<matrix.size(); ++row) { matrix[row][0] = 0; }
        }

        if (firstColHas0)
        {
            for (int col = 0; col<matrix[0].size(); ++col) { matrix[0][col] = 0; }
        }
    }
};