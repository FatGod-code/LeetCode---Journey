class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int results = nums[0];
        std::pair<int, int> table = {nums[0] , nums[0]};
        for (int idx = 1; idx<nums.size(); ++idx)
        {
            //if (nums[idx]<0) { std::swap(table.first, table.second); }
            /*if (nums[idx]==0) { table = {0, 0}; }
            else*/
        
            int value1 = table.first;
            int value2 = table.second;
            table.first = std::max({nums[idx], value1*nums[idx], value2*nums[idx]});
            table.second = std::min({nums[idx], value1*nums[idx], value2*nums[idx]});

            std::cout << table.first << table.second << std::endl;

            results = std::max(table.first, results);
        }

        return results;
    }
};