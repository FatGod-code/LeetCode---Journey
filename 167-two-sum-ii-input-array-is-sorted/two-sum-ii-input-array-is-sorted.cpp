class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left = 0;
        int right = static_cast<int>(numbers.size())-1;
        while (left<right)
        {
            const auto leftValue = numbers[left];
            const auto rightValue = numbers[right];
            const auto sum = leftValue+rightValue;
            
            if (sum==target) { return {left+1, right+1}; }
            else if (sum<target) { ++left;}
            else { --right; }
        }

        return {};
    }
};