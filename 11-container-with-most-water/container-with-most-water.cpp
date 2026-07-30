class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int results = 0;

        int left = 0;
        int right = static_cast<int>(height.size())-1;
        while (left<right)
        {
            const auto leftValue = height[left];
            const auto rightValue = height[right];
            
            const auto h = std::min(leftValue, rightValue);
            const auto w = right-left;
            results = std::max(h*w, results);

            if (height[left]<height[right])
            {
                while (left<right && height[left]<=leftValue) { ++left; }
            }
            else
            {
                while (left<right && height[right]<=rightValue) { --right; }
            }
        }

        return results;
    }
};