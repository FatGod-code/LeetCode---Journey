class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        std::vector<int> dirs{0, 1, 0, -1, 0};

        int results = 0;

        for (int row = 0; row<grid.size(); ++row)
        {
            for (int col = 0; col<grid[0].size(); ++col)
            {
                if (grid[row][col]!='1') { continue; }

                std::queue<std::pair<int, int>> que;
                que.push({row, col});
                grid[row][col] = '#';
                while (!que.empty())
                {
                    int size = que.size();
                    for (int s = 0; s<size; ++s)
                    {
                        auto [y, x] = que.front();
                        que.pop();

                        for (int d = 0; d<4; ++d)
                        {
                            int yn = y+dirs[d];
                            int xn = x+dirs[d+1];
                            if (yn<0 || yn>=grid.size() || xn<0 || xn>=grid[0].size() ||
                                grid[yn][xn]!='1') { continue; }

                            que.push({yn, xn});
                            grid[yn][xn] = '#';
                        }
                    }
                }

                ++results;
            }
        }

        return results;
    }
};