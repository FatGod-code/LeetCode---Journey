class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size()==0 || matrix[0].size()==0) { return false; }

        int rowSize = static_cast<int>(matrix.size());
        int colSize = static_cast<int>(matrix[0].size());

        int left = 0;
        int right = rowSize*colSize;
        while (left<right)
        {
            int middle = left+(right-left)/2;

            int row = middle/colSize;
            int col = middle%colSize;

            if (matrix[row][col]==target) { return true; }
            else if (matrix[row][col]<target) { left = middle+1; }
            else { right = middle; }
        }

        return false;
    }
};