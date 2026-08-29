class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        std::vector<int> results(temperatures.size(), 0);

        std::vector<int> sta;
        sta.reserve(temperatures.size());
        for (int idx = 0; idx<temperatures.size(); ++idx)
        {
            while (!sta.empty() && temperatures[idx]>temperatures[sta.back()])
            {
                auto top = sta.back();
                sta.pop_back();
                
                results[top] = idx-top;
            }

            sta.emplace_back(idx);
        }

        return results;
    }
};