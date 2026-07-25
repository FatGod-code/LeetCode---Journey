class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> timesTable;
        for (const auto ele : nums) { ++timesTable[ele]; }

        std::vector<std::vector<int>> bucket(nums.size()+1);
        for (const auto& ele : timesTable)
        {
            const auto index = ele.second;
            bucket[index].emplace_back(ele.first);
        }

        std::vector<int> results(k);
        int index = 0;
        for (int idx = bucket.size()-1; idx>=0; --idx)
        {
            for (const auto ele : bucket[idx])
            {
                results[index++] = ele;
                if (index==k) { return results; }
            }
        }

        return results;
    }
};