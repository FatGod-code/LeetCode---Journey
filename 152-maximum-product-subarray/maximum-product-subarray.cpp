class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int results = nums[0];
        std::pair<int, int> table = {nums[0], nums[0]};
        for (int idx = 1; idx<nums.size(); ++idx)
        {
            if (nums[idx]<0) { std::swap(table.first, table.second); }
            /*if (nums[idx]==0) { table = {0, 0}; }
            else*/
        
            table.first = std::max({nums[idx], table.first*nums[idx]});
            table.second = std::min({nums[idx], table.second*nums[idx]});

            results = std::max(table.first, results);
        }

        return results;
    }
};