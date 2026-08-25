class Solution {
public:
    int missingMultiple(vector<int>& nums, int k)
    {
        int value = 0;
        std::sort(nums.begin(), nums.end());
        for (int idx = 0; idx<nums.size(); ++idx)
        {
            if (nums[idx]%k) { continue; }
            
            int product = nums[idx]/k;
            if (product==(value+1)) { value = product; }
            else { return (value+1)*k; }

            while (idx+1<nums.size() && nums[idx+1]==nums[idx]) { ++idx; }
        }

        return (value+1)*k; 
    }
};