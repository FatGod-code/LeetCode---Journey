class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        std::vector<std::vector<bool>> rowTable(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> colTable(9, std::vector<bool>(9, false));
        std::vector<std::vector<bool>> subBoxTable(9, std::vector<bool>(9, false));

        for (int row = 0; row<board.size(); ++row)
        {
            for (int col = 0; col<board[0].size(); ++col)
            {
                int value = board[row][col];
                if (value=='.') { continue; }

                int index = value-'0'-1;
                int subIdx = (row/3)*3+(col/3);
                if (rowTable[row][index] || colTable[col][index] || subBoxTable[subIdx][index]) { return false; }

                rowTable[row][index] = true;
                colTable[col][index] = true;
                subBoxTable[subIdx][index] = true;
            }
        }

        return true;
    }
};