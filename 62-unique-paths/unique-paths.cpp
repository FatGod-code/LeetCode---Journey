class Solution {
public:
    int uniquePaths(int m, int n)
    {
        std::vector<std::vector<int>> table(m, std::vector<int>(n, 1));
        for (int row = 1; row<m; ++row)
        {
            for (int col = 1; col<n; ++col)
            {
                table[row][col] = table[row-1][col]+table[row][col-1];
            }
        }
        
        return table.back().back();
    }
};