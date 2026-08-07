class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size();
        int lastValue = nums.back();
        while (left<right)
        {
            int middle = left+(right-left)/2;

            if (nums[middle]<=lastValue) { right = middle; }
            else { left = middle+1; }
        }

        int end = nums.size();
        if (target>lastValue)
        {
            right = left;
            end = left;
            left = 0;
        }
        else { right = nums.size(); }

        while (left<right)
        {
            int middle = left+(right-left)/2;

            if (nums[middle]>=target) { right = middle; }
            else{ left = middle+1; }
        }

        if (left==end) { return -1;}
        return nums[left]==target ? left : -1;
    }
};