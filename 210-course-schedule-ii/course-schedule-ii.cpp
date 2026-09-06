class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        std::vector<int> table(numCourses);
        std::vector<std::vector<int>> graph(numCourses);
        for (const auto& ele : prerequisites)
        {
            graph[ele[1]].emplace_back(ele[0]);
            ++table[ele[0]];
        }

        std::queue<int> que;
        for (int idx = 0; idx<table.size(); ++idx)
        {
            if (table[idx]==0) { que.push(idx); }
        }

        std::vector<int> results;
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto course = que.front();
                que.pop();
                
                results.emplace_back(course);

                for (const auto ele : graph[course])
                {
                    --table[ele];
                    if (table[ele]==0) { que.push(ele); }
                }
            }

        }

        return results.size()==numCourses ? results : std::vector<int>{};
    }
};