class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space)
    {
        long long results = 0;
        std::unordered_map<int, long long> table;
        for (int idx = 0; idx<tasks.size(); ++idx)
        {
            auto found = table.find(tasks[idx]);
            if (found!=table.end() && results<found->second)
            {
                results = found->second;
            }
            table[tasks[idx]] = results+space+1;
            ++results;
        }

        return results;
    }
};