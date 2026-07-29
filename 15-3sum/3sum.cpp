class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        std::vector<std::vector<int>> results;

        std::sort(nums.begin(), nums.end());
        for (int idx = 0; idx<nums.size(); ++idx)
        {
            if (nums[idx]>0) { break; }

            int left = idx+1;
            int right = nums.size()-1;
            while (left<right)
            {
                int leftValue = nums[left];
                int rightValue = nums[right];

                int sum = leftValue+rightValue;
                if (sum==(-nums[idx]))
                {
                    results.push_back({nums[idx], leftValue, rightValue});

                    while (left<right && nums[left]==leftValue) { ++left; }
                    while (left<right && nums[right]==rightValue) { --right; }
                }
                
                else if (sum<(-nums[idx]))
                {
                    while (left<right && nums[left]==leftValue) { ++left; }
                }
                else
                {
                    while (left<right && nums[right]==rightValue) { --right; }
                }
            }

            while (idx+1<nums.size() && nums[idx+1]==nums[idx]) { ++idx; }
        }

        return results;
    }
};