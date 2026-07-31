class Solution {
public:
    int trap(vector<int>& height)
    {
        int results = 0;

        int left = 0;
        int leftMax = 0;

        int right = height.size()-1;
        int rightMax = 0;

        while (left<right)
        {
            leftMax = std::max(height[left], leftMax);
            rightMax = std::max(height[right], rightMax);

            if (leftMax<rightMax)
            {
                results += (leftMax-height[left]);
                ++left;
            }
            else
            {
                results += (rightMax-height[right]);
                --right;
            }
        }

        return results;
    }
};