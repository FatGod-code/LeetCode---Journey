class Solution {
public:
    int minimumDeletions(vector<int>& nums)
    {
        auto maxItr = std::ranges::max_element(nums);
        int maxDistanceToBegin = std::distance(nums.begin(), maxItr)+1;
        int maxDistanceToEnd = std::distance(maxItr, nums.end());

        std::cout << maxDistanceToBegin << " " << maxDistanceToEnd << std::endl;

        auto minItr = std::ranges::min_element(nums);
        int minDistanceToBegin = std::distance(nums.begin(), minItr)+1;
        int minDistanceToEnd = std::distance(minItr, nums.end());

        std::cout << minDistanceToBegin << " " << minDistanceToEnd << std::endl;

        std::vector<int> candidates{std::max(maxDistanceToBegin, minDistanceToBegin),
                                    std::max(maxDistanceToEnd, minDistanceToEnd),
                                    maxDistanceToBegin+minDistanceToEnd,
                                    maxDistanceToEnd+minDistanceToBegin};
        return *(std::ranges::min_element(candidates));

    }
};