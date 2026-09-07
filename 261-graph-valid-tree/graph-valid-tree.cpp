class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if (edges.size()!=n-1) { return false; }

        std::vector<std::vector<int>> tree(n);
        for (const auto& ele : edges)
        {
            tree[ele[0]].emplace_back(ele[1]);
            tree[ele[1]].emplace_back(ele[0]);
        }

        std::unordered_set<int> visited;
        
        int numNodes = 0;

        std::queue<int> que;
        que.push(0);
        visited.emplace(0);
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto node = que.front();
                que.pop();

                ++numNodes;

                for (const auto ele : tree[node])
                {
                    if (visited.find(ele)!=visited.end()) { continue; }

                    que.push(ele);
                    visited.emplace(ele);
                }
            }
        }

        return numNodes==n;
    }
};