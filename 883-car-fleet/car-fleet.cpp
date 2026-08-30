class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        std::vector<std::pair<int, int>> positionSort(position.size());
        for (int idx = 0; idx<position.size(); ++idx)
        {
            positionSort[idx] = {position[idx], speed[idx]};
        }
        std::sort(positionSort.begin(), positionSort.end(), std::greater<std::pair<int, int>>());

        int results = 0;
        double maxTime = 0.0; 
        for (const auto& ele : positionSort)
        {
            double time = (target-ele.first)/static_cast<double>(ele.second);
            if (time<=maxTime) { continue; }

            maxTime = time;
            ++results;
        }

        return results;
    }
};