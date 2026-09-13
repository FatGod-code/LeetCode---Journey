class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for (const auto ele : nums) { sum += ele; }

        if (sum%2) { return false; };

        int target = sum/2;
        std::vector<bool> table(target+1, false);
        table[0] = true;
        for (const auto ele : nums)
        {
            for (int idx = table.size()-1; idx>=0; --idx)
            {
                if (idx-ele<0) { break; }

                if (table[idx]) { continue; }
                if (table[idx-ele]) { table[idx] = true; }
            }

            if (table.back()) { return true; }
        }

        return false;
    }
};