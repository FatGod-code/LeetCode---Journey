class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for (const auto ele :nums) { sum += ele; }

        if (sum%2) { return false; }

        std::vector<bool> table(sum/2+1, false);
        table[0] = true;
        for (const auto ele : nums)
        {
            for (int idx = table.size()-1; idx>=0; --idx)
            {
                if (table[idx]) { continue; }

                if (idx-ele>=0 && table[idx-ele]) { table[idx] = true; }
            }
        }

        return table.back();
    }
};