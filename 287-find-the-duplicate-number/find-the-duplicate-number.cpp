class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = nums[0];
        int quick = nums[nums[0]];
        while (quick!=slow)
        {
            slow = nums[slow];
            quick = nums[quick];
            quick = nums[quick];
        }

        int idx = 0;
        while (slow!=idx)
        {
            slow = nums[slow];
            idx = nums[idx];
        }

        return slow;
    }
};