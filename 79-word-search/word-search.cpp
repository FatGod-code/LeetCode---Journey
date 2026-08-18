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
        if (row<0 || row>=board.size() || col<0 || col>=board[0].size()) { return false; }
        if (!table[row][col]) { return false; }

        

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

        table[row][col] = false;

        auto results = FindString(board, word, idx+1, row-1, col, table) ||
                       FindString(board, word, idx+1, row+1, col, table) ||
                       FindString(board, word, idx+1, row, col-1, table) ||
                       FindString(board, word, idx+1, row, col+1, table);

        table[row][col] = true;
        return results;
    }
};