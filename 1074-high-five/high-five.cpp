class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items)
    {
        std::map<int, std::priority_queue<int>> heaps;
        for (int idx = 0; idx<items.size(); ++idx)
        {
            heaps[items[idx][0]].push(items[idx][1]);
        }

        std::vector<std::vector<int>> results;
        for (auto& ele : heaps)
        {
            int sum = 0;
            for (int i = 0; i<5; ++i)
            {
                sum += ele.second.top();
                ele.second.pop();
            }

            results.push_back({ele.first, sum/5});
        }

        return results;
    }
};