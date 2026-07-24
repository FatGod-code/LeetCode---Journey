class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> timesTable;
        for (int idx = 0; idx<nums.size(); ++idx) { ++timesTable[nums[idx]]; }

        std::vector<std::pair<int, int>> timesVec;
        for (const auto& ele : timesTable)
        {
            timesVec.push_back({ele.second, ele.first});
        }

        std::sort(timesVec.begin(), timesVec.end(), [](std::pair<int, int> a, std::pair<int, int> b) { return a.first>b.first; });

        std::vector<int> results;
        for (int i = 0; i<k; ++i) { results.emplace_back(timesVec[i].second); }

        return results;
    }
};