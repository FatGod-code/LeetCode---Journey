class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        std::vector<int> hs(heights.size()+2, 0);
        for (int idx = 0; idx<heights.size(); ++idx) { hs[idx+1] = heights[idx]; }

        int results = 0;

        std::stack<int> sta;
        for (int idx = 0; idx<hs.size(); ++idx)
        {
            while (sta.size() && hs[idx]<hs[sta.top()])
            {
                int height = hs[sta.top()];
                sta.pop();

                int surface = height*(idx-sta.top()-1);
                results = std::max(surface, results);
            }

            sta.emplace(idx);
        }

        return results;
    }
};