class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> results;
        
        std::stack<std::pair<int, std::vector<int>>> sta;
        sta.push({0, {}});
        while (!sta.empty())
        {
            auto [idx, subset] = sta.top();
            sta.pop();

            if (idx<nums.size())
            {
                int value = nums[idx];
                subset.emplace_back(value);
                sta.push({idx+1, subset});

                while (idx+1<nums.size() && nums[idx]==nums[idx+1]) { ++idx; }

                subset.pop_back();
                sta.push({idx+1, subset});
            }
            else { results.emplace_back(subset); }
        }

        return results;
    }
};