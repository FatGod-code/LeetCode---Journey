class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        std::vector<int> tail;
        tail.emplace_back(nums[0]);
        for (int idx = 1; idx<nums.size(); ++idx)
        {
            auto itr =std::ranges::lower_bound(tail, nums[idx]);
            if (itr==tail.end()) { tail.emplace_back(nums[idx]); }
            else { *itr = nums[idx]; }
        }

        return tail.size();
    }

private:
    int bs(const std::vector<int>& nums, int value)
    {
        int left = 0;
        int right = nums.size();
        while (left<right)
        {
            int middle = left+(right-left)/2;
            
            if (nums[middle]>=value) { right = middle; }
            else { left = middle+1; }
        }

        return left;
    }
};