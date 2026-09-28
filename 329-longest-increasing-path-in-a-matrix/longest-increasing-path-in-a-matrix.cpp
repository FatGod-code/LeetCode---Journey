class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        std::vector<std::vector<int>> table(matrix.size(), std::vector<int>(matrix[0].size(), 0));
        for (int row = 0; row<matrix.size(); ++row)
        {
            for (int col = 0; col<matrix[0].size(); ++col) { dfs(matrix, row, col, -1, 1, table); }
        }

        int results = 0;
        for (int row = 0; row<table.size(); ++row)
        {
            auto maxIter = std::ranges::max_element(table[row]);
            results = std::max(*maxIter, results);
        }

        return results;
    }

    void dfs(const std::vector<std::vector<int>>& matrix, int row, int col,
             int lastValue, int numSteps, std::vector<std::vector<int>>& table)
    {
        if (row<0 || row>=matrix.size() || col<0 || col>=matrix[0].size()) { return; }
        if (matrix[row][col]<=lastValue) { return; }
        if (table[row][col]>=numSteps) { return; }

        table[row][col] = numSteps;

        int value = matrix[row][col];
        dfs(matrix, row-1, col, value, numSteps+1, table);
        dfs(matrix, row+1, col, value, numSteps+1, table);
        dfs(matrix, row, col-1, value, numSteps+1, table);
        dfs(matrix, row, col+1, value, numSteps+1, table);
    }
};