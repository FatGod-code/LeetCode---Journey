class DetectSquares {
public:
    DetectSquares()
    {
        for (int row = 0; row<1001; ++row)
        {
            for (int col = 0; col<1001; ++col) { mPoints[row][col] = 0; }
        }
    }
    
    void add(vector<int> point)
    {
        int x = point[0];
        int y = point[1];

        if (mPoints[y][x]==0) { mYinX[x].emplace_back(y); }
        ++mPoints[y][x];
    }
    
    int count(vector<int> point)
    {
        int results = 0;
        for (const auto ele : mYinX[point[0]])
        {
            int length = std::abs(ele-point[1]);
            if (length==0) { continue; }

            if (point[0]-length>=0)
            {
                int numPoints1 = mPoints[ele][point[0]];
                int numPoints2 = mPoints[point[1]][point[0]-length];
                int numPoints3 = mPoints[ele][point[0]-length];

                results += numPoints1*numPoints2*numPoints3;
            }

            if (point[0]+length<=1000)
            {
                int numPoints1 = mPoints[ele][point[0]];
                int numPoints2 = mPoints[point[1]][point[0]+length];
                int numPoints3 = mPoints[ele][point[0]+length];
                results += numPoints1*numPoints2*numPoints3;
            }
        }

        return results;
    }

private:
    int mPoints[1001][1001];
    std::vector<int> mYinX[1001];
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */