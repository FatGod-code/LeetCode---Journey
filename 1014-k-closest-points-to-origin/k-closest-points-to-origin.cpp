class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        auto comp = [] (const std::pair<int, int>& a, const std::pair<int, int>& b)
        {
            int valueA = a.first*a.first+a.second*a.second;
            int valueB = b.first*b.first+b.second*b.second;
            return valueA<valueB;
        };
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> pque;
        for (const auto& point : points)
        {
            if (pque.size()<k) { pque.push({point[0], point[1]}); }
            else
            {
                if (comp({point[0], point[1]}, {pque.top().first, pque.top().second}))
                {
                    pque.pop();
                    pque.push({point[0], point[1]});
                }
            }
        }

        std::vector<std::vector<int>> results(k, std::vector<int>(2));
        int idx = 0;
        while (!pque.empty())
        {
            results[idx] = {pque.top().first, pque.top().second};
            pque.pop();
            ++idx;
        }


        return results;
    }
};