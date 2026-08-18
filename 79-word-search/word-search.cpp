class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        if (board.size()*board[0].size()<word.size()) { return false; }

        std::vector<std::vector<bool>> table(board.size(), std::vector<bool>(board[0].size(), true));
        for (int row = 0; row<board.size(); ++row)
        {
            for (int col = 0; col<board[0].size(); ++col)
            {
                
                if (FindString(board, word, 0, row, col, table)) { return true; }
            }
        }

        return false;
    }

    bool FindString(const std::vector<std::vector<char>>& board, const std::string& word,
                    int idx, int row, int col, std::vector<std::vector<bool>>& table)
    {
        table[row][col] = false;

        if (idx==word.size()-1 && board[row][col]==word[idx])
        {
            table[row][col] = true;
            return true;
        }
        if (board[row][col]!=word[idx])
        {
            table[row][col] = true;
            return false;
        }

        bool down = false;
        if (row-1>=0 && table[row-1][col]) { down = FindString(board, word, idx+1, row-1, col, table); }

        bool up = false;
        if (row+1<board.size() && table[row+1][col]) { up = FindString(board, word, idx+1, row+1, col, table); }

        bool left = false;
        if (col-1>=0 && table[row][col-1]) { left = FindString(board, word, idx+1, row, col-1, table); }

        bool right = false;
        if (col+1<board[0].size() && table[row][col+1]) { right = FindString(board, word, idx+1, row, col+1, table); }

        table[row][col] = true;
        return down || up || left || right;
    }
};