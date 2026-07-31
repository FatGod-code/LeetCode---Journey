class Solution {
public:
    int trap(vector<int>& height)
    {
        int results = 0;

        int left = 0;
        int leftMax = height[left];

        int right = height.size()-1;
        int rightMax = height[right];

        while (left<right)
        {
            if (leftMax<rightMax)
            {
                ++left;
                results += std::max(leftMax-height[left], 0);
                leftMax = std::max(height[left], leftMax);
                
            }
            else
            {
                --right;
                results += std::max(rightMax-height[right], 0);
                rightMax = std::max(height[right], rightMax);
                
            }
        }

        return results;
    }
};