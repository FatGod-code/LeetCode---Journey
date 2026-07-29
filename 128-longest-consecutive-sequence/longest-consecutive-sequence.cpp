class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {   
        int results = 0;
        int length = 0;

        std::sort(nums.begin(), nums.end());
        for (int idx = 0; idx<nums.size(); ++idx)
        {
            if (idx-1>=0 && nums[idx]==nums[idx-1]) { continue; }

            if (idx-1>=0 && nums[idx]-1==nums[idx-1]) { ++length; }
            else { length = 1; }
            
            results = std::max(length, results);
        }

        return results;
    }
};