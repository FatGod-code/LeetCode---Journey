class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        std::vector<uint16_t> colTable(9, 0x0000);
        std::vector<uint16_t> subTable(9, 0x0000);

        for (int row = 0; row<9; ++row)
        {
            uint16_t rowFlags = 0x0000;
            for (int col = 0; col<9; ++col)
            {
                const auto value = board[row][col];
                if (value=='.') { continue; }

                int idx = value-'0';
                uint16_t mask = 0;
                mask |= (1<<idx);

                int subIdx = (row/3)*3+(col/3);
                if (rowFlags & mask || colTable[col] & mask || subTable[subIdx] & mask) { return false; }

                rowFlags |= mask;
                colTable[col] |= mask;
                subTable[subIdx] |= mask;
            }
        }

        return true;
    }
};