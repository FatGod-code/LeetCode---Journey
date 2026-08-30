class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        std::vector<int> h(heights.size()+2, 0);
        for (int idx = 0; idx<heights.size(); ++idx) { h[idx+1] = heights[idx]; }

        int results = 0;
        std::stack<std::pair<int, int>> sta;
        for (int idx = 0; idx<h.size(); ++idx)
        {
            while (sta.size() && h[idx]<sta.top().first)
            {
                auto [height, index] = sta.top();
                sta.pop();

                int surface = height*(idx-sta.top().second-1);
                results = std::max(surface, results);
            }

            sta.push({h[idx], idx});
        }

        return results;
    }
};