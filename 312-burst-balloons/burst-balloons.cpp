class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
        std::vector<int> numbers(nums.size()+2, 1);
        for (int idx = 0; idx<nums.size(); ++idx) { numbers[idx+1] = nums[idx]; }

        std::vector<std::vector<int>> table(numbers.size(), std::vector<int>(numbers.size(), -1));
        return dfs(numbers, 1, nums.size(), table);
    }

    int dfs(const std::vector<int>& numbers, int left, int right,
            std::vector<std::vector<int>>& table)
    {
        if (left>right) { return 0; }
        if (table[left][right]!=-1) { return table[left][right]; }

        int results = 0;
        for (int idx = left; idx<=right; ++idx)
        {
            auto leftValue = dfs(numbers, left, idx-1, table);
            auto rightValue = dfs(numbers, idx+1, right, table);

            int midValue = numbers[left-1]*numbers[idx]*numbers[right+1];
            results = std::max(leftValue+rightValue+midValue, results);
        }

        table[left][right] = results;
        return results;
    }
};