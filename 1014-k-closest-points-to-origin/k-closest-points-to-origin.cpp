class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        auto comp = [] (const std::vector<int>& a, const std::vector<int>& b)
        {
            return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
        };
        
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comp)> pque;
        for (const auto& point : points)
        {
            pque.push(point);
            if (pque.size()>k) { pque.pop(); }
        }

        std::vector<std::vector<int>> results(k);
        int idx = 0;
        while (!pque.empty())
        {
            results[idx] = pque.top();
            pque.pop();
            ++idx;
        }

        return results;
    }
};