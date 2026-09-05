class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        std::vector<std::vector<int>> table1(heights.size(), std::vector<int>(heights[0].size(), 0));

        

        std::queue<std::pair<int, int>> que;
        for (int row = 0; row<heights.size(); ++row)
        {
            que.push({row, 0});
            table1[row][0] = 1;
            std::cout << row << " " << 0 << std::endl;
        }
        std::cout << std::endl;

        for (int col = 0; col<heights[0].size(); ++col)
        {
            que.push({0, col});
            table1[0][col] = 1;
            std::cout << 0 << " " << col << std::endl;
        }
        

        BFS(heights, que, table1);

        std::vector<std::vector<int>> table2(heights.size(), std::vector<int>(heights[0].size(), 0));

        std::queue<std::pair<int, int>> que2;
        for (int row = 0; row<heights.size(); ++row)
        {
            que2.push({row, heights[0].size()-1});
            table2[row][heights[0].size()-1] = 1;
            std::cout << row << " " << heights[0].size()-1 << std::endl;}
        std::cout << std::endl;

        for (int col = 0; col<heights[0].size(); ++col)
        {
            que2.push({heights.size()-1, col});
            table2[heights.size()-1][col] = 1;
            std::cout << heights.size()-1 << " " << col << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;

        
        BFS(heights, que2, table2);

        std::vector<std::vector<int>> results;
        for (int row = 0; row<table1.size(); ++row)
        {
            for (int col = 0; col<table1[0].size(); ++col)
            {
                if (table1[row][col] && table2[row][col]) { results.push_back({row, col}); }
            }
        }

        return results;
    }

    void BFS(std::vector<std::vector<int>>& heights,
             std::queue<std::pair<int, int>>& que, std::vector<std::vector<int>>& table)
    {
        std::vector<int> dirs{0, 1, 0, -1, 0};

        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto [row, col] = que.front();
                que.pop();

                //table[row][col] = 1;

                for (int d = 0; d<4; ++d)
                {
                    int y = row+dirs[d];
                    int x = col+dirs[d+1];
                    if (y<0 || y>=heights.size() || x<0 || x>=heights[0].size() ||
                        heights[row][col]>heights[y][x] || table[y][x]!=0) { continue; }

                    que.push({y, x});
                    table[y][x] = 1;
                }
            }
        }
    }
};