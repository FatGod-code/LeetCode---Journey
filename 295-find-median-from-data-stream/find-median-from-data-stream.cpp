class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num)
    {
        int idx = FindInsertIdx(num);
        //std::cout << idx << std::endl;
//        mValues.emplace_back()
        mValues.insert(std::next(mValues.begin(), idx), num);
    }
    
    double findMedian()
    {
        int halfSize = mValues.size()/2;
        if (mValues.size()%2) { return mValues[halfSize]; }
        else { return (mValues[halfSize-1]+mValues[halfSize])/2.0; }
    }

private:
    std::vector<int> mValues;

    int FindInsertIdx(int num)
    {
        int left = 0;
        int right = mValues.size();
        while (left<right)
        {
            int middle = left+(right-left)/2;
            
            if (mValues[middle]>=num) { right = middle; }
            else { left = middle+1; }
        }

        return left;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */