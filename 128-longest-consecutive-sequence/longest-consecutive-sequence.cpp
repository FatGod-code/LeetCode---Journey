class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int results = 0;

        std::unordered_set<int> table(nums.begin(), nums.end());
        for (const auto ele : table)
        {
            if (table.find(ele-1)!=table.end()) { continue; }

            int value = ele;
            while (table.find(++value)!=table.end()) {}
            
            results = std::max(value-ele, results);
        }

        return results;
    }
};