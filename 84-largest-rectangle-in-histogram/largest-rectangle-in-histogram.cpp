class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        std::vector<int> h(heights.size()+2, 0);
        for (int idx = 0; idx<heights.size(); ++idx) { h[idx+1] = heights[idx]; }

        int results = 0;
        std::vector<int> sta;
        for (int idx = 0; idx<h.size(); ++idx)
        {
            while (sta.size() && h[idx]<h[sta.back()])
            {
                auto index = sta.back();
                sta.pop_back();

                int surface = h[index]*(idx-sta.back()-1);
                results = std::max(surface, results);
            }

            sta.emplace_back(idx);
        }

        return results;
    }
};