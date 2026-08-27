class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        std::vector<int> table(26);
        for (const auto ele : tasks) { ++table[ele-'A']; }

        std::priority_queue<std::pair<int, char>> pq;
        for (int idx = 0; idx<table.size(); ++idx)
        {
            if (table[idx]>0) { pq.push({table[idx], 'A'+idx}); }
        }

        std::vector<char> tasksOrder;
        int results = 0;
        std::queue<std::tuple<char, int, int>> q;
        while (!pq.empty() || !q.empty())
        {
            if (!q.empty())
            {
                auto [task, times, okTime] = q.front();
                
                if (results>=okTime)
                {
                    pq.push({times, task});
                    q.pop();
                }
            }

            if (!pq.empty())
            {
                auto [times, task] = pq.top();
                pq.pop();

                tasksOrder.emplace_back(task);
                if (times-1>0) { q.push({task, times-1, results+n+1}); }
            }
            else { tasksOrder.emplace_back('#'); }

            ++results;
        }

        return results;
    }
};