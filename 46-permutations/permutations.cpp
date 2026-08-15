class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        std::vector<std::vector<int>> results;
        
        std::stack<std::pair<std::vector<int>, std::vector<bool>>> sta;
        sta.push({{}, std::vector<bool>(nums.size(), false)});
        while (!sta.empty())
        {
            auto [permutation, table] = sta.top();
            sta.pop();

            if (permutation.size()==nums.size())
            {
                results.emplace_back(permutation);
                continue;
            }

            for (int idx = 0; idx<nums.size(); ++idx)
            {
                if (table[idx]) { continue; }

                permutation.emplace_back(nums[idx]);
                table[idx] = true;

                sta.push({permutation, table});
                permutation.pop_back();
                table[idx] = false;
            }
        }

        return results;
    }
};