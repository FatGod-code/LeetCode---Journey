class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space)
    {
        long long results = 0;
        std::unordered_map<int, long long> table;
        for (const auto ele : tasks)
        {
            if (table.count(ele)) { results = std::max(table[ele], results); }
            
            table[ele] = results+space+1;
            ++results;
        }

        return results;
    }
};