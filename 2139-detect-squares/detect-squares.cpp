class DetectSquares {
public:
    DetectSquares() {}
    
    void add(vector<int> point) { ++mPoints[point[0]][point[1]]; }
    
    int count(vector<int> point)
    {
        auto foundX = mPoints.find(point[0]);
        if (foundX==mPoints.end()) { return 0; }

        int results = 0;
        for (const auto& ele : foundX->second)
        {
            int length = std::abs(ele.first-point[1]);
            if (length==0) { continue; }

            auto numPoints1 = findPoint(point[0]-length, point[1]);
            auto numPoints2 = findPoint(point[0]-length, ele.first);
            results += (ele.second*numPoints1*numPoints2);

            numPoints1 = findPoint(point[0]+length, point[1]);
            numPoints2 = findPoint(point[0]+length, ele.first);
            results += (ele.second*numPoints1*numPoints2);
        }

        return results;
    }

private:
    std::unordered_map<int, std::unordered_map<int, int>> mPoints;

    int findPoint(int x, int y)
    {
        auto foundX = mPoints.find(x);
        if (foundX==mPoints.end()) { return 0; }

        auto foundY = foundX->second.find(y);
        if (foundY==foundX->second.end()) { return 0; }

        return foundY->second;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */