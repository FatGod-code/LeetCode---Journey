class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> results;
//        std::vector<int> combination;

        std::sort(candidates.begin(), candidates.end());
        
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

    void
    GenerateCombinations(const std::vector<int>& candidates, int target, int startIdx,
                         std::vector<int>& combination, std::vector<std::vector<int>>& results)
    {
        if (target==0)
        {
            results.emplace_back(combination);
            return;
        }

        if (target<0) { return; }

        for (int idx = startIdx; idx<candidates.size(); ++idx)
        {
            int value = candidates[idx];
            if (value>target) { break; }

            combination.emplace_back(value);
            
            GenerateCombinations(candidates, target-value, idx, combination, results);
            combination.pop_back();
        }
    }
};