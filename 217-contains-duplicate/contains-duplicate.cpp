class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        int value = nums.front();
        for (int idx = 1; idx<nums.size(); ++idx)
        {
            if (nums[idx]==value) { return true; }
            else { value = nums[idx]; }
        }

        return false;
    }
};