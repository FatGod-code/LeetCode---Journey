class Solution {
public:
    bool Decision(const std::vector<int>& nums, int middle, int target)
    {
        //int lastValue = 

        return true;
    }

    int search(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size();
        int lastValue = nums.back();
        while (left<right)
        {
            int middle = left+(right-left)/2;
            int value = nums[middle];

            if ((value>lastValue && target>lastValue) ||
                (value<=lastValue && target<=lastValue))
            {
                if (value>=target) { right = middle; }
                else { left = middle+1; }
            }
            else
            {
                if (value<=lastValue && target>lastValue) { right = middle; }
                else { left = middle+1; }
                
            }
        }

        if (left==nums.size()) { return -1; }
        return nums[left]==target ? left : -1;
    }
};