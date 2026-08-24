class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        QuickSelect(points, 0, points.size()-1, k-1);
        points.resize(k);

        return points;
    }

    int CountDistance(const std::vector<int>& point)
    {
        return point[0]*point[0]+point[1]*point[1];
    }

    int Partition(std::vector<std::vector<int>>& nums, int left, int right, int targetIdx)
    {
        int piviotDistance = CountDistance(nums[right]);
        int i = left;

        for (int j = left; j<right; ++j)
        {
            int distance = CountDistance(nums[j]);
            if (distance<piviotDistance)
            {
                std::swap(nums[i], nums[j]);
                ++i;
            }
        }
        std::swap(nums[i], nums[right]);

        return i;
    }

    void QuickSelect(std::vector<std::vector<int>>& nums, int left, int right, int targetIdx)
    {
        if (left>=right) { return; }

        int piviotIdx = Partition(nums, left, right, targetIdx);
        if (piviotIdx==targetIdx) { return; }
        else if (piviotIdx>targetIdx) { QuickSelect(nums, left, piviotIdx-1, targetIdx); }
        else { QuickSelect(nums, piviotIdx+1, right, targetIdx); }
    }
};