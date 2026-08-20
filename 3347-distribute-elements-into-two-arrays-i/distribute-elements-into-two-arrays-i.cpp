class Solution {
public:
    vector<int> resultArray(vector<int>& nums)
    {
        std::vector<int> arr1{nums[0]};
        std::vector<int> arr2{nums[1]};

        for (int idx = 2; idx<nums.size(); ++idx)
        {
            if (arr1.back()>arr2.back()) { arr1.emplace_back(nums[idx]); }
            else { arr2.emplace_back(nums[idx]); }
        }

        arr1.insert(arr1.end(), arr2.cbegin(), arr2.cend());
        return arr1;
    }
};