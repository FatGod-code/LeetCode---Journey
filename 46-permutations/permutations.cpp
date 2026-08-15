class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> results;
        results.emplace_back(nums);

        while (GenerateNextPermutation(nums)) { results.emplace_back(nums); }

        return results;
    }

    bool GenerateNextPermutation(std::vector<int>& nums)
    {
        int maxValue = INT_MIN;
        
        int idx = nums.size()-1;
        for (; idx>=0; --idx)
        {
            if (nums[idx]<maxValue) { break; }
            maxValue = nums[idx];
        }

        if (idx<0) { return false; }

        int targetIdx = nums.size()-1;
        while (targetIdx>=0 && nums[targetIdx]<=nums[idx]) { --targetIdx; }

        std::swap(nums[idx], nums[targetIdx]);
        std:reverse(nums.begin()+idx+1, nums.end());

        return true;
    }
};