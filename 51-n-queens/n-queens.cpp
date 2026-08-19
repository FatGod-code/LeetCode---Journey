class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> results;
        std::vector<std::string> solution;
        
        std::vector<bool> colTable(n, false);
        std::vector<bool> diagTable(2*n, false);
        std::vector<bool> rdiagTable(2*n, false);

        SolveQueenPuzzle(n, 0, colTable, diagTable, rdiagTable, solution, results);

        return results;
    }

    void SolveQueenPuzzle(int n, int numQueens,
                          std::vector<bool>& colTable, std::vector<bool>& diagTable, std::vector<bool>& rdiagTable,
                          std::vector<std::string>& solution, std::vector<std::vector<std::string>>& results)
    {
        if (numQueens==n)
        {
            results.emplace_back(solution);
            return;
        }

        for (int col = 0; col<n; ++col)
        {
            if (colTable[col]) { continue; }
            if (diagTable[numQueens-col+n]) { continue; }
            if (rdiagTable[numQueens+col]) { continue; }

            colTable[col] = true;
            diagTable[numQueens-col+n] = true;
            rdiagTable[numQueens+col] = true;

            std::string str(n, '.');
            str[col] = 'Q';
            solution.emplace_back(str);

            SolveQueenPuzzle(n, numQueens+1, colTable, diagTable, rdiagTable, solution, results);

            colTable[col] = false;
            diagTable[numQueens-col+n] = false;
            rdiagTable[numQueens+col] = false;

            solution.pop_back();
        }
    }

};