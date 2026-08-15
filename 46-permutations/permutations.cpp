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
        int idx = nums.size()-2;
        for (; idx>=0; --idx)
        {
            if (nums[idx]<=nums[idx+1]) { break; }
        }

        if (idx<0) { return false; }

        int targetIdx = nums.size()-1;
        while (targetIdx>=0 && nums[targetIdx]<=nums[idx]) { --targetIdx; }

        std::swap(nums[idx], nums[targetIdx]);
        std::reverse(nums.begin()+idx+1, nums.end());

        return true;
    }
};