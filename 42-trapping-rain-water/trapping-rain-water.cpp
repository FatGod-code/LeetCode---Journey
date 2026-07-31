class Solution {
public:
    int trap(vector<int>& height)
    {
        int results = 0;
        std::vector<std::pair<int, int>> table(height.size(), {0, 0});
        for (int idx = 1; idx<height.size(); ++idx)
        {
            table[idx].first = std::max(height[idx-1], table[idx-1].first);
        }

        for (int idx = height.size()-2; idx>=0; --idx)
        {
            table[idx].second = std::max(height[idx+1], table[idx+1].second);
        }

        for (int idx = 0;idx<height.size(); ++idx)
        {
            int h = std::min(table[idx].first, table[idx].second);
            results += std::max(h-height[idx], 0);
        }
        
        return results;
    }
};