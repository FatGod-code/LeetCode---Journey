class Solution {
public:
    int missingMultiple(vector<int>& nums, int k)
    {
        std::unordered_set<int> table(nums.begin(), nums.end());

        int target = k;
        while (table.count(target)) { target += k; }

        return target;
    }
};