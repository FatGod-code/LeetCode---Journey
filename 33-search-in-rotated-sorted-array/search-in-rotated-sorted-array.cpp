class Solution {
public:
    bool Decision(int middleValue, int target, int lastValue)
    {
        bool isSameArea = (middleValue<=lastValue)==(target<=lastValue);
        if (isSameArea)
        {
            if (middleValue>=target) { return true; }
        }
        else
        {
            if (middleValue<=lastValue && target>lastValue) { return true; }
        }

        return false;
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

            if (Decision(value, target, lastValue)) { right = middle; }
            else { left = middle+1; }
        }

        if (left==nums.size()) { return -1; }
        return nums[left]==target ? left : -1;
    }
};