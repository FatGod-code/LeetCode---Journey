class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        std::vector<int> h(heights.size()+2, 0);
        for (int idx = 0; idx<heights.size(); ++idx) { h[idx+1] = heights[idx]; }

        int results = 0;
        std::stack<int> sta;
        for (int idx = 0; idx<h.size(); ++idx)
        {
            while (sta.size() && h[idx]<h[sta.top()])
            {
                auto index = sta.top();
                sta.pop();

                int surface = h[index]*(idx-sta.top()-1);
                results = std::max(surface, results);
            }

            sta.push(idx);
        }

        return results;
    }
};