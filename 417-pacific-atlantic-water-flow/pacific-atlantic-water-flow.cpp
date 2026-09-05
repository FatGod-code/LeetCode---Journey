class Solution {
public:

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& ocean,
             int r, int c) {

        int m = heights.size();
        int n = heights[0].size();

        ocean[r][c] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            // Out of bounds
            if (nr < 0 || nr >= m ||
                nc < 0 || nc >= n)
                continue;

            // Already visited
            if (ocean[nr][nc])
                continue;

            // Can't move downhill in reverse
            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(heights, ocean, nr, nc);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific: top row
        for (int c = 0; c < n; c++) {
            dfs(heights, pacific, 0, c);
        }

        // Pacific: left column
        for (int r = 0; r < m; r++) {
            dfs(heights, pacific, r, 0);
        }

        // Atlantic: bottom row
        for (int c = 0; c < n; c++) {
            dfs(heights, atlantic, m - 1, c);
        }

        // Atlantic: right column
        for (int r = 0; r < m; r++) {
            dfs(heights, atlantic, r, n - 1);
        }

        vector<vector<int>> result;

        // Find cells reachable from both oceans
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};