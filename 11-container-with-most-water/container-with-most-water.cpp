class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int results = 0;

        int left = 0;
        int right = static_cast<int>(height.size())-1;
        while (left<right)
        {
            const auto h = std::min(height[left], height[right]);
            const auto w = right-left;
            results = std::max(h*w, results);

            if (height[left]<height[right]) { ++left; }
            else { --right; }
        }

        return results;
    }
};