class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        std::vector<std::vector<int>> results;

        std::stack<std::pair<int, std::vector<int>>> sta;
        sta.push({-1, {}});
        while (!sta.empty())
        {
            auto [idx, subset] = sta.top();
            sta.pop();

            if (idx+1<nums.size())
            {
                sta.push({idx+1, subset});
                
                subset.emplace_back(nums[idx+1]);
                sta.push({idx+1, subset});
            }
            else { results.emplace_back(subset); }
        }

        return results;
    }
};