class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        std::queue<std::pair<int, int>> que;
        for (int row = 0; row<grid.size(); ++row)
        {
            for (int col = 0; col<grid[0].size(); ++col)
            {
                if (grid[row][col]==2) { que.push({row, col}); }
            }
        }

        std::vector<int> dirs{0, 1, 0, -1, 0};

        int results = 0;
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

                    if (y<0 || y>=grid.size() || x<0 || x>=grid[0].size() ||
                        grid[y][x]==2 || grid[y][x]==0) { continue; }

                    grid[y][x] = 2;
                    que.push({y, x});
                }
                
            }
            ++results;
        }

        for (int row = 0; row<grid.size(); ++row)
        {
            for (int col = 0; col<grid[0].size(); ++col)
            {
                if (grid[row][col]==1) { return -1; }
            }
        }

        return results==0 ? 0 : results-1;
    }
};