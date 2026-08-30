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

        std::stack<double> sta;
        for (const auto& ele : positionSort)
        {
            double time = (target-ele.first)/static_cast<double>(ele.second);
            if (sta.size() && time<=sta.top()) { continue; }

            sta.emplace(time);
        }

        return sta.size();
    }
};