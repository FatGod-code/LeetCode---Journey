class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        for (int row = 0; row<9; ++row)
        {
            uint16_t flags = 0x00000000;
            for (int col = 0; col<9; ++col)
            {
                const auto value = board[row][col];
                if (value=='.') { continue; }

                uint16_t mask = 0;
                int idx = value-'0';
                mask |= (1<<idx);

                if (flags & mask) { return false; }
                flags |= mask;
            }
        }

        for (int col = 0; col<9; ++col)
        {
            uint16_t flags = 0x00000000;
            for (int row = 0; row<9; ++row)
            {
                const auto value = board[row][col];
                if (value=='.') { continue; }

                uint16_t mask = 0;
                int idx = value-'0';
                mask |= (1<<idx);

                if (flags & mask) { return false; }
                flags |= mask;
            }
        }

        for (int bigRow = 0; bigRow<3; ++bigRow)
        {
            for (int bigCol = 0; bigCol<3; ++bigCol)
            {
                uint16_t flags = 0x00000000;
                for (int row = 0; row<3; ++row)
                {
                    for (int col = 0; col<3; ++col)
                    {
                        const auto value = board[bigRow*3+row][bigCol*3+col];
                        if (value=='.') { continue; }

                        uint16_t mask = 0;
                        int idx = value-'0';
                        mask |= (1<<idx);

                        if (flags & mask) { return false; }
                        flags |= mask;
                    }
                }
            }
        }

        return true;
    }
};