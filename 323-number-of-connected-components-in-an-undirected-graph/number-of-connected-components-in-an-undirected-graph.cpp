class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        std::vector<std::vector<int>> graph(n);
        for (const auto& ele : edges)
        {
            graph[ele[0]].emplace_back(ele[1]);
            graph[ele[1]].emplace_back(ele[0]);
        }

        std::vector<bool> visited(n, false);
        int results = 0;
        for (int idx = 0; idx<n; ++idx)
        {
            if (visited[idx]) { continue; }

            std::queue<int> que;
            que.push(idx);
            visited[idx] = true;
            while (!que.empty())
            {
                int size = que.size();
                for (int s = 0; s<size; ++s)
                {
                    auto node = que.front();
                    que.pop();

                    for (const auto ele : graph[node])
                    {
                        if (visited[ele]) { continue; }

                        que.push(ele);
                        visited[ele] = true;
                    }
                }
            }

            ++results;
        }

        return results;
    }
};