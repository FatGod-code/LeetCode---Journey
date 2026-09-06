class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        std::vector<std::vector<bool>> tableP(heights.size(), std::vector<bool>(heights[0].size(), false));
        std::queue<std::pair<int, int>> que;
        for (int row = 0; row<heights.size(); ++row)
        {
            que.push({row, 0});
            tableP[row][0] = true;
        }

        for (int col = 0; col<heights[0].size(); ++col)
        {
            que.push({0, col});
            tableP[0][col] = true;
        }

        BFS(heights, tableP, que);

        std::vector<std::vector<bool>> tableA(heights.size(), std::vector<bool>(heights[0].size(), false));
        for (int row = 0; row<heights.size(); ++row)
        {
            que.push({row, heights[0].size()-1});
            tableA[row][heights[0].size()-1] = true;
        }

        for (int col = 0; col<heights[0].size(); ++col)
        {
            que.push({heights.size()-1, col});
            tableA[heights.size()-1][col] = true;
        }

        BFS(heights, tableA, que);

        std::vector<std::vector<int>> results;
        for (int row = 0; row<heights.size(); ++row)
        {
            for (int col = 0; col<heights[0].size(); ++col)
            {
                if (tableP[row][col] && tableA[row][col]) { results.push_back({row, col}); }
            }
        }

        return results;
    }

    void BFS(const std::vector<std::vector<int>>& heights,
             std::vector<std::vector<bool>>& table,
             std::queue<std::pair<int, int>>& que)
    {
        std::vector<int> dirs{0, 1, 0, -1, 0};

        while (!que.empty())
        {
            auto [row, col] = que.front();
            que.pop();

            for (int d = 0; d<4; ++d)
            {
                int y = row+dirs[d];
                int x = col+dirs[d+1];
                if (y<0 || y>=heights.size() || x<0 || x>=heights[0].size() ||
                    heights[row][col]>heights[y][x] || table[y][x]) { continue; }

                que.push({y, x});
                table[y][x] = true;
            }
        }
    }
};