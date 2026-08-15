class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());

        std::vector<std::vector<int>> results;
        std::stack<std::pair<int, std::pair<int, std::vector<int>>>> sta;
        sta.push({target, {0, {}}});
        while (!sta.empty())
        {
            auto [t, p] = sta.top();
            auto [startIdx, combination] = p;
            sta.pop();

            if (t==0) { results.emplace_back(combination); }
            if (t<0) { continue; }

            for (int idx = startIdx; idx<candidates.size(); ++idx)
            {
                int value = candidates[idx];
                if (value>t) { break; }

                combination.emplace_back(value);
                sta.push({t-value, {idx+1, combination}});
                combination.pop_back();

                while (idx+1<candidates.size() && candidates[idx+1]==candidates[idx]) { ++idx; }
            }
        }

        return results;
    }
};