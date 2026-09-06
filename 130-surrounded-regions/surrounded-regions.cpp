class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        std::queue<std::pair<int, int>> que;
        for (int row = 0; row<board.size(); ++row)
        {
            if (board[row][0]=='O')
            {
                que.push({row, 0});
                board[row][0] = '#';
            }
            if (board[row][board[0].size()-1]=='O')
            {
                que.push({row, board[0].size()-1});
                board[row][board[0].size()-1] = '#';
            }
        }

        for (int col = 0; col<board[0].size()-1; ++col)
        {
            if (board[0][col]=='O')
            {
                que.push({0, col});
                board[0][col] = '#';
            }
            if (board[board.size()-1][col]=='O')
            {
                que.push({board.size()-1, col});
                board[board.size()-1][col] = '#';
            }
        }

        std::vector<int> dirs{0, 1, 0, -1, 0};
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto [row, col] = que.front();
                que.pop();

                for (int d = 0; d<4; ++d)
                {
                    int y = row+dirs[d];
                    int x = col+dirs[d+1];
                    if (y<0 || y>=board.size() || x<0 || x>=board[0].size()-1 ||
                        board[y][x]!='O') { continue; }

                    que.push({y, x});
                    board[y][x] = '#';
                }
            }
        }

        for (int row = 0; row<board.size(); ++row)
        {
            for (int col = 0; col<board[0].size(); ++col)
            {
                if (board[row][col]=='O') { board[row][col] = 'X'; }
                else if (board[row][col]=='#') { board[row][col] = 'O'; }
            }
        }
    }
};