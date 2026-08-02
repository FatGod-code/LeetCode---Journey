class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        std::unordered_map<int, int> table;
        for (const auto ele : nums)
        {
            if (table[ele]>0) { return ele; }
            ++table[ele];
        }

        return 0;
    }
};