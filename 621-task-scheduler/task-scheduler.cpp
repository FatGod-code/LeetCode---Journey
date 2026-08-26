class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        std::unordered_map<char, int> timesTable;
        for (const auto ele : tasks) { ++timesTable[ele]; }

        int maxTimes = 0;
        for (const auto& ele : timesTable) { maxTimes = std::max(ele.second, maxTimes); }

        unsigned long results = (maxTimes-1)*(n+1);
        for (const auto& ele : timesTable)
        {
            if (ele.second==maxTimes) { ++results; }
        }

        return std::max(tasks.size(), results);
    }
};