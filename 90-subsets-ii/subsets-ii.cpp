class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        int times = 1 << nums.size();
        std::vector<std::vector<int>> results;
        results.reserve(times);

        for (int t = 0; t<times; ++t)
        {
            std::vector<int> subset;
            bool toPush = true;

            for (int idx = 0; idx<nums.size(); ++idx)
            {
                bool b = (t & (1 << idx));
                if (idx-1>=0 && nums[idx]==nums[idx-1])
                {
                    bool bLast = (t & (1 << (idx-1)));
                    if (b && !bLast)
                    {
                        toPush = false;
                        break;
                    }
                }

                if (b) { subset.emplace_back(nums[idx]); }
            }

            if (toPush) { results.emplace_back(subset); }
            
        }

        return results;
    }
};