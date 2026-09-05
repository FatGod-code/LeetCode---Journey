class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms)
    {
        std::queue<std::pair<int, int>> que;
        for (int row = 0; row<rooms.size(); ++row)
        {
            for (int col = 0; col<rooms[0].size(); ++col)
            {
                if (rooms[row][col]==0) { que.push({row, col}); }
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
                    if (y<0 || y>=rooms.size() || x<0 || x>=rooms[0].size() ||
                        rooms[y][x]==-1 || rooms[y][x]<=rooms[row][col]+1) { continue; }

                    rooms[y][x] = rooms[row][col]+1;
                    que.push({y, x});
                }
            }
        }
    }
};