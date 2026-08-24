class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::vector<int> table(20001, 0);
        for (const auto ele : nums) { ++table[ele+10000]; }

        int idx = table.size()-1;
        for (; idx>=0; --idx)
        {
            k -= table[idx];
            if (k<=0) { break; }
        }

        return idx-10000;
    }
};