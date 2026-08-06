class Solution {
public:
    int findMin(vector<int>& nums)
    {
        if (nums.size()==1) { return nums[0]; }
        if (nums[0]<nums[nums.size()-1]) { return nums[0]; }

        int left = 0;
        int right = nums.size();
        int firstValue = nums[0];
        while (left<right)
        {
            int middle = left+(right-left)/2;

            if (nums[middle]<firstValue) { right = middle; }
            else { left = middle+1; }

        }

        return nums[left];
    }
};