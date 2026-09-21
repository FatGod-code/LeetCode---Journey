class DetectSquares {
public:
    DetectSquares() {}
    
    void add(const vector<int>& point)
    {
        int x = point[0];
        int y = point[1];

        if (mPoints[y][x]==0) { mYinX[x].emplace_back(y); }
        ++mPoints[y][x];
    }
    
    int count(const vector<int>& point)
    {
        int results = 0;
        for (const auto ele : mYinX[point[0]])
        {
            int length = std::abs(ele-point[1]);
            if (length==0) { continue; }

            int numPoints1 = mPoints[ele][point[0]];
            if (point[0]-length>=0)
            {
                int numPoints2 = mPoints[point[1]][point[0]-length];
                int numPoints3 = mPoints[ele][point[0]-length];

                results += numPoints1*numPoints2*numPoints3;
            }

            if (point[0]+length<=1000)
            {
                int numPoints2 = mPoints[point[1]][point[0]+length];
                int numPoints3 = mPoints[ele][point[0]+length];
                results += numPoints1*numPoints2*numPoints3;
            }
        }

        return results;
    }

private:
    int mPoints[1001][1001]{0};
    std::vector<int> mYinX[1001];
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */