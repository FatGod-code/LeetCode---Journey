class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        int idx = nums.size()-2;
        while (idx>=0 && nums[idx]>=nums[idx+1]) { --idx; }

        if (idx>=0)
        {            
            int targetIdx = nums.size()-1;
            while (targetIdx>=0 && nums[targetIdx]<=nums[idx]) { --targetIdx; }

            std::swap(nums[idx], nums[targetIdx]);
        }

        std::reverse(nums.begin()+idx+1, nums.end());
    }
};