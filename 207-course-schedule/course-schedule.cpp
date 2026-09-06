class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        std::vector<int> table(numCourses);
        std::unordered_map<int, std::vector<int>> graph;
        for (const auto& ele : prerequisites)
        {
            graph[ele[1]].emplace_back(ele[0]);
            ++table[ele[0]];
        }

        std::unordered_set<int> coursesTaken;
        std::queue<int> que;
        for (int idx = 0; idx<table.size(); ++idx)
        {
            if (table[idx]==0)
            {
                que.push(idx);
                coursesTaken.emplace(idx);
            }
        }

        int numCoursesTaken = 0;
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto course = que.front();
                que.pop();

                ++numCoursesTaken;

                for (const auto ele : graph[course])
                {
                    if (coursesTaken.find(ele)!=coursesTaken.end()) { continue; }
                    
                    --table[ele];
                    if (table[ele]==0)
                    {
                        que.push(ele);
                        coursesTaken.emplace(ele);
                    }
                }
            }
        }

        std::cout << numCoursesTaken << " " << numCourses;

        return numCoursesTaken==numCourses;
    }
};