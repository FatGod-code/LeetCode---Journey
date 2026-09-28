class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int results = 0;

        std::vector<std::vector<int>> table(matrix.size(), std::vector<int>(matrix[0].size(), 0));
        for (int row = 0; row<matrix.size(); ++row)
        {
            for (int col = 0; col<matrix[0].size(); ++col) { (void) dfs(matrix, row, col, -1, table, results); }
        }

        return results;
    }

    int dfs(const std::vector<std::vector<int>>& matrix, int row, int col,
             int lastValue, std::vector<std::vector<int>>& table, int& results)
    {
        if (row<0 || row>=matrix.size() || col<0 || col>=matrix[0].size()) { return 0; }
        if (matrix[row][col]<=lastValue) { return 0; }
        if (table[row][col]!=0) { return table[row][col]; }
        
        int value = matrix[row][col];
        int number = std::max({dfs(matrix, row-1, col, value, table, results),
                               dfs(matrix, row+1, col, value, table, results),
                               dfs(matrix, row, col-1, value, table, results),
                               dfs(matrix, row, col+1, value, table, results)});
        
        table[row][col] = number+1;
        results = std::max(table[row][col], results);

        return table[row][col];
    }
};