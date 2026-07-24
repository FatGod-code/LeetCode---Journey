class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> timesTable;
        for (const auto ele : nums) { ++timesTable[ele]; }

        std::vector<std::pair<int, int>> timesVec(timesTable.begin(), timesTable.end());
        std::sort(timesVec.begin(), timesVec.end(), [](const auto& a, const auto& b) { return a.second>b.second; });

        std::vector<int> results;
        for (int i = 0; i<k; ++i) { results.emplace_back(timesVec[i].first); }

        return results;
    }
};