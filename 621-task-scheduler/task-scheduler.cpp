class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        auto cmp = [](const std::pair<char, int>& a, const std::pair<char, int>& b)
        {
            return a.second<b.second;
        };

        std::vector<int> timesTable(26);
        for (const auto ele : tasks) { ++timesTable[ele-'A']; }

        std::priority_queue<std::pair<int, char>> pq;
        for (int idx = 0; idx<timesTable.size(); ++idx)
        {
            if (timesTable[idx]!=0) { pq.push({timesTable[idx], idx+'A'}); }
        }

        std::vector<char> results;

        int time = 0;
        std::queue<std::tuple<char, int, int>> que;
        while (!pq.empty() || !que.empty())
        {
            if (!que.empty())
            {
                auto [task, times, coolTime] = que.front();
                
                if (coolTime<time)
                {
                    que.pop();
                    pq.push({times, task});
                }
            }

            if (!pq.empty())
            {
                auto top = pq.top();
                pq.pop();

                results.emplace_back(top.second);
                if (top.first-1>0) { que.push({top.second, top.first-1, time+n}); }
            }
            else { results.emplace_back('#'); }
            
            ++time;
        }

        for (const auto ele : results) { std::cout << ele << " "; }

        return time;
    }
};