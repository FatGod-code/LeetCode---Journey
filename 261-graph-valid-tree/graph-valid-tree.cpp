class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if (edges.size()!=n-1) { return false; }

        std::vector<std::vector<int>> graph(n);
        for (const auto& ele : edges)
        {
            graph[ele[0]].emplace_back(ele[1]);
            graph[ele[1]].emplace_back(ele[0]);
        }

        std::vector<bool> visited(n, false);

        int numNodes = 0;

        std::queue<int> que;
        que.push(0);
        visited[0] = true;
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
                    if (visited[ele]) { continue; }

                    que.push(ele);
                    visited[ele] = true;
                }
            }
        }

        return numNodes==n;
    }
};