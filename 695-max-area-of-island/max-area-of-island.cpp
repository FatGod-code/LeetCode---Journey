class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        std::vector<int> dirs{0, 1, 0, -1, 0};

        int results = 0;

        for (int row = 0; row<grid.size(); ++row)
        {
            for (int col = 0; col<grid[0].size(); ++col)
            {
                if (grid[row][col]!=1) { continue; }

                std::queue<std::pair<int, int>> que;
                que.push({row, col});
                grid[row][col] = 2;

                int area = 0;
                while (!que.empty())
                {
                    auto [y, x] = que.front();
                    que.pop();

                    ++area;

                    for (int d = 0; d<4; ++d)
                    {
                        int yn = y+dirs[d];
                        int xn = x+dirs[d+1];
                        if (yn<0 || yn>=grid.size() || xn<0 || xn>=grid[0].size() ||
                            grid[yn][xn]!=1) { continue; }

                        que.push({yn, xn});
                        grid[yn][xn] = 2;
                    }
                    
                }

                results = std::max(area, results);
            }
        }


        return results;
    }
};