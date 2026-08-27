class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space)
    {
        long long results = 0;
        std::unordered_map<long long, long long> table;
        for (int idx = 0; idx<tasks.size(); ++idx)
        {
            auto found = table.find(tasks[idx]);
            if (found!=table.end())
            {
                if (results>=found->second)
                {
                    found->second = results+space+1;
                    ++results;
                }
                else
                {
                    results = found->second;
                    found->second = results+space+1;
                    ++results;
                }
            }
            else
            {
                table.emplace(tasks[idx], results+space+1);
                ++results;
            }
        }

        return results;
    }
};