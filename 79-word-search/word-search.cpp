class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        if (board.size()*board[0].size()<word.size()) { return false; }

        for (int row = 0; row<board.size(); ++row)
        {
            for (int col = 0; col<board[0].size(); ++col)
            {
                if (FindString(board, word, 0, row, col)) { return true; }
            }
        }

        return false;
    }

    bool FindString(std::vector<std::vector<char>>& board, const std::string& word,
                    int idx, int row, int col)
    {
        if (row<0 || row>=board.size() || col<0 || col>=board[0].size()) { return false; }
        if (board[row][col]=='#') { return false; }

        if (board[row][col]!=word[idx]) { return false; }
        if (idx==word.size()-1 && board[row][col]==word[idx]) { return true; }

        const auto temp = board[row][col];
        board[row][col] = '#';
        auto results = FindString(board, word, idx+1, row-1, col) ||
                       FindString(board, word, idx+1, row+1, col) ||
                       FindString(board, word, idx+1, row, col-1) ||
                       FindString(board, word, idx+1, row, col+1);

        board[row][col] = temp;
        return results;
    }
};