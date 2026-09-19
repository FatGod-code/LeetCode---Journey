class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());

        std::vector<int> results(m*n);
        int ridx = 0;

        int left = 0;
        int right = n-1;

        int top = 0;
        int bottom = m-1;
        while (left<=right && top<=bottom)
        {
            for (int idx = left; idx<=right; ++idx) { results[ridx++] = matrix[top][idx]; }
            ++top;
            if (top>bottom) { break; }

            for (int idx = top; idx<=bottom; ++idx) { results[ridx++] = matrix[idx][right]; }
            --right;
            if (right<left) { break; }

            for (int idx = right; idx>=left; --idx) { results[ridx++] = matrix[bottom][idx]; }
            --bottom;
            if (bottom<top) { break; }

            for (int idx = bottom; idx>=top; --idx) { results[ridx++] = matrix[idx][left]; }
            ++left;
            if (left>right) { break; }
        }

        return results;
    }
};