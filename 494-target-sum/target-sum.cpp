class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int sum = 0;
        for (const auto ele : nums) { sum += ele; }

        int value = sum+target;
        if (value%2 || std::abs(target)>sum) { return 0; }

        std::vector<int> table(value/2+1);
        table[0] = 1;
        for (const auto ele : nums)
        {
            for (int idx = table.size()-1; idx>=ele; --idx)
            {
                table[idx] += table[idx-ele];
            }
        }

        return table.back();
    }
};