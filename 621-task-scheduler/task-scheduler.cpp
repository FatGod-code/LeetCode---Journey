class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        int maxFreq = 0;
        std::vector<int> timesTable(26, 0);
        for (const auto ele : tasks)
        {
            ++timesTable[ele-'A'];
            maxFreq = std::max(timesTable[ele-'A'], maxFreq);
        }

        int maxFreqCount = 0;
        for (const auto ele : timesTable)
        {
            if (ele==maxFreq) { ++maxFreqCount; }
        }

        int results = (maxFreq-1)*(n+1)+maxFreqCount;
        return results<tasks.size() ? tasks.size() : results;
    }
};