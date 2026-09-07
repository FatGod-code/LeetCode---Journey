class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        std::vector<std::vector<int>> graph(n);
        for (const auto& ele : edges)
        {
            graph[ele[0]].emplace_back(ele[1]);
            graph[ele[1]].emplace_back(ele[0]);
        }

        int numNodes = 0;
        
        std::vector<std::pair<bool, int>> visited(n, std::pair<bool, int>{false, -1});
        std::queue<int> que;
        que.push(0);
        visited[0] = {true, -1};
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto node = que.front();
                que.pop();

                ++numNodes;

                for (const auto ele : graph[node])
                {
                    if (visited[ele].first)
                    {
                        if (visited[node].second==ele) { continue; }
                        else { return false;}
                    }

                    que.push(ele);
                    visited[ele] = {true, node};
                }
            }
        }

        return numNodes==n;
    }
};