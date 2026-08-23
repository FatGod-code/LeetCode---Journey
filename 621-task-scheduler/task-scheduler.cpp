class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        std::unordered_map<char, int> timesTable;
        for (const auto ele : tasks) { ++timesTable[ele]; }

        std::priority_queue<int> pque;
        for (const auto ele : timesTable) { pque.emplace(ele.second); }

        int maxTimes = pque.top();
        int results = (maxTimes-1)*(n+1);
        int numEmpty = results;
        while (!pque.empty())
        {
            int value = pque.top();
            pque.pop();
            
            if (value==maxTimes)
            {
                ++results;
                numEmpty -= (value-1);
            }
            else { numEmpty -= value; }
            
            
            if (numEmpty<=0) { results += value; }

            
        }


        return numEmpty<=0 ? tasks.size() : results;

    }
};