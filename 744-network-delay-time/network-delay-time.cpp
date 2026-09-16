class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        std::vector<std::vector<std::pair<int, int>>> graph(n);
        std::vector<int> inDegrees(n);
        for (const auto& ele : times)
        {
            graph[ele[0]-1].push_back({ele[1]-1, ele[2]});
            ++inDegrees[ele[1]-1];
        }

        std::vector<int> delayTimes(n, INT_MAX);
        delayTimes[k-1] = 0;

        std::vector<bool> visited(n, false);
        std::queue<int> que;
        que.push(k-1);
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto node = que.front();
                que.pop();

                for (const auto ele : graph[node])
                {
                    if (delayTimes[node]+ele.second<delayTimes[ele.first])
                    {
                        delayTimes[ele.first] = delayTimes[node]+ele.second;
                        que.push(ele.first);
                    }
                }
            }
        }

        if (std::ranges::count(delayTimes, INT_MAX)) { return -1; }
        for (const auto ele : delayTimes) { std::cout << ele << " "; }
        
        return *std::ranges::max_element(delayTimes);
    }
};