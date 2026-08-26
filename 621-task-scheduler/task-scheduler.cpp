class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        std::vector<int> timesTable(26);
        for (const auto ele : tasks) { ++timesTable[ele-'A']; }

        int maxTimes = *(std::ranges::max_element(timesTable));
        int maxTimesCount = std::ranges::count(timesTable, maxTimes);
        int results = (maxTimes-1)*(n+1)+maxTimesCount;
        
        return std::max(static_cast<int>(tasks.size()), results);
    }
};