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

    int Partition(std::vector<int>& nums, int left, int right)
    {
        int idx = left+std::rand()%(right-left+1);
        std::swap(nums[idx], nums[right]);

        int i = left;
        for (int j = left; j<right; ++j)
        {
            if (nums[j]<nums[right])
            {
                std::swap(nums[j], nums[i]);
                ++i;
            }
        }
        std::swap(nums[i], nums[right]);

        return i;
    }
};