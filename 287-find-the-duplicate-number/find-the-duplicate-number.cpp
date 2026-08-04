class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = 0;
        int quick = 0;
        while (1)
        {
            slow = nums[slow];
            quick = nums[quick];
            quick = nums[quick];

            if (quick==slow) { break; }
        }

        int idx = 0;
        while (1)
        {
            slow = nums[slow];
            idx = nums[idx];

            if (slow==idx) { break; }
        }

        return slow;
    }
};