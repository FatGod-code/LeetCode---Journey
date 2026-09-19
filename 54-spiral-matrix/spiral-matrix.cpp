class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        int size = m*n;

        std::vector<int> results(m*n);
        int ridx = 0;

        int left = 0;
        int right = n-1;
        
        int top = 0;
        int bottom = m-1;

        while (left<=right && top<=bottom)
        {
            for (int col = left; col<=right; ++col) { results[ridx++] = matrix[top][col]; }
            ++top;
            if (top>bottom) { break; }


            for (int row = top; row<=bottom; ++row) { results[ridx++] = matrix[row][right]; }
            --right;
            if (right<left) { break; }

            for (int col = right; col>=left; --col) { results[ridx++] = matrix[bottom][col]; }
            --bottom;
            if (bottom<top) { break; }

            for (int row = bottom; row>=top; --row) { results[ridx++] = matrix[row][left]; }
            ++left;
            if (left>right) { break; }
        }

        return results;
    }
};