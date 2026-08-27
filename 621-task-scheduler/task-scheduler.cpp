class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        std::vector<int> table(26);
        for (const auto ele : tasks) { ++table[ele-'A']; }

        int maxTimes = *(std::ranges::max_element(table));
        int numMaxTimesTasks = std::ranges::count(table, maxTimes);
        int results = (maxTimes-1)*(n+1)+numMaxTimesTasks;
        
        return std::max(static_cast<int>(tasks.size()), results);
    }
};