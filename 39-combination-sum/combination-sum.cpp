class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());

        std::vector<std::vector<int>> results;        
        
        std::stack<std::pair<int, std::pair<int, std::vector<int>>>> sta;
        sta.push({0, {target, {}}});
        while (!sta.empty())
        {
            auto [startIdx, p] = sta.top();
            auto [t, combination] = p;
            sta.pop();

            if (t==0)
            {
                results.emplace_back(combination);
                continue;
            }

            for (int idx = startIdx; idx<candidates.size(); ++idx)
            {
                int value = candidates[idx];
                if (value>t) { break; }
                
                combination.emplace_back(value);
                sta.push({idx, {t-value, combination}});
                combination.pop_back();
            }
        }
        
        return results;
    }
};