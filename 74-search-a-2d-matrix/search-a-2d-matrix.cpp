class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int left = 0;
        int right = static_cast<int>(matrix.size()*matrix[0].size());
        while (left<right)
        {
            int middle = left+(right-left)/2;

            int row = middle/matrix[0].size();
            int col = middle%matrix[0].size();

            if (matrix[row][col]==target) { return true; }
            else if (matrix[row][col]<target) { left = middle+1; }
            else { right = middle; }
        }

        return false;
    }
};