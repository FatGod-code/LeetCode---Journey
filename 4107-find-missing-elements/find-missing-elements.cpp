class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums)
    {
        std::vector<int> results;
        
        std::sort(nums.begin(), nums.end());
        int startValue = nums[0]+1;
        int endValue = nums.back();
        int idx = 1;
        while (startValue<endValue)
        {
            if (startValue==nums[idx])
            {
                ++startValue;
                ++idx;
            }
            else if (startValue<nums[idx])
            {
                results.emplace_back(startValue);
                ++startValue;
            }
            else { ++idx; }
        }

        return results;
    }
};