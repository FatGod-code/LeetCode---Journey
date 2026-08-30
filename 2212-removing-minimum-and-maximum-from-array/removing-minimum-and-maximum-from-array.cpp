class Solution {
public:
    int minimumDeletions(vector<int>& nums)
    {
        auto [minItr, maxItr] = std::ranges::minmax_element(nums);
        
        int numMaxDeleteFromBegin = std::distance(nums.begin(), maxItr)+1;
        int numMaxDeleteFronmEnd = std::distance(maxItr, nums.end());

        int numMinDeleteFromBegin = std::distance(nums.begin(), minItr)+1;
        int numMinDeleteFromEnd = std::distance(minItr, nums.end());

        std::vector<int> candidates{std::max(numMaxDeleteFromBegin, numMinDeleteFromBegin),
                                    std::max(numMaxDeleteFronmEnd, numMinDeleteFromEnd),
                                    numMaxDeleteFromBegin+numMinDeleteFromEnd,
                                    numMaxDeleteFronmEnd+numMinDeleteFromBegin};
        return *(std::ranges::min_element(candidates));

    }
};