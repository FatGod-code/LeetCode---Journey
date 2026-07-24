class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> timesTable;
        for (const auto ele : nums) { ++timesTable[ele]; }

        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pque;
        for (const auto& ele : timesTable)
        {
            if (pque.size()<k) { pque.push({ele.second, ele.first}); }
            else
            {
                if (ele.second>pque.top().first)
                {
                    pque.pop();
                    pque.push({ele.second, ele.first});
                }
            }
        }

        std::vector<int> results(k);
        for (int i = 0; i<k; ++i)
        {
            results[i] = pque.top().second;
            pque.pop();
        }

        return results;
    }
};