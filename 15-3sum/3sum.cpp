class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        std::vector<std::vector<int>> results;

        std::sort(nums.begin(), nums.end());
        for (int idx = 0; idx<nums.size(); ++idx)
        {
            if (nums[idx]>0) { break; }
            if (idx>0 && nums[idx]==nums[idx-1]) { continue; }

            int left = idx+1;
            int right = static_cast<int>(nums.size())-1;
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
                else if (sum<(-nums[idx])) { ++left; }
                else { --right; }
            }
        }

        return results;
    }
};