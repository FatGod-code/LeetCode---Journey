class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int row = 0; row<board.size(); ++row)
        {
            std::vector<int> table(10, 0);
            for (int col = 0; col<board[0].size(); ++col)
            {
                const auto value = board[row][col];
                if (value=='.') { continue; }
                
                if (table[value-'0']>0) { return false;}
                ++table[value-'0'];
            }
        }

        for (int col = 0; col<board[0].size(); ++col)
        {
            std::vector<int> table(10, 0);
            for (int row = 0; row<board.size(); ++row)
            {
                const auto value = board[row][col];
                if (value=='.') { continue; }
                
                if (table[value-'0']>0) { return false;}
                ++table[value-'0'];
            }
        }

        for (int bigRow = 0; bigRow<3; ++bigRow)
        {
            for (int bigCol = 0; bigCol<3; ++bigCol)
            {
                std::vector<int> table(10, 0);
                for (int row = 0; row<3; ++row)
                {
                    for (int col = 0; col<3; ++col)
                    {
                        const auto value = board[bigRow*3+row][bigCol*3+col];
                        if (value=='.') { continue; }

                        if (table[value-'0']>0) { return false;}
                        ++table[value-'0'];
                    }
                }
            }
        }

        return true;
    }
};