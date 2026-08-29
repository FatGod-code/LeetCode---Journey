class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        std::vector<int> results(temperatures.size(), 0);

        std::stack<int> sta;
        for (int idx = 0; idx<temperatures.size(); ++idx)
        {
            if (sta.empty()) { sta.emplace(idx); }
            else if (temperatures[idx]<=temperatures[sta.top()]) { sta.emplace(idx); }
            else
            {
                while (sta.size() && temperatures[idx]>temperatures[sta.top()])
                {
                    auto top = sta.top();
                    sta.pop();
                    
                    results[top] = idx-top;
                }

                sta.emplace(idx);
            }
        }

        return results;
    }
};