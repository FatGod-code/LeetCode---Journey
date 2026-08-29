class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num)
    {
        mMaxHeap.emplace(num);
        if (mMinHeap.size()>0 && mMaxHeap.top()>mMinHeap.top())
        {
            int value = mMaxHeap.top();
            mMaxHeap.pop();

            mMinHeap.emplace(value);
        }
        
        int maxSize = mMaxHeap.size();
        int minSize = mMinHeap.size();

        if (maxSize>minSize+1)
        {
            while (maxSize>minSize+1)
            {
                int value = mMaxHeap.top();
                mMaxHeap.pop();

                mMinHeap.emplace(value);

                maxSize = mMaxHeap.size();
                minSize = mMinHeap.size();
            }
        }
        else if (minSize>maxSize)
        {
            while (minSize>maxSize)
            {
                int value = mMinHeap.top();
                mMinHeap.pop();

                mMaxHeap.emplace(value);

                maxSize = mMaxHeap.size();
                minSize = mMinHeap.size();
            }
        }
    }
    
    double findMedian()
    {
        int maxSize = mMaxHeap.size();
        int minSize = mMinHeap.size();

        if ((maxSize+minSize)%2) { return mMaxHeap.top(); }
        return (mMaxHeap.top()+mMinHeap.top())/2.0;
    }

private:
    std::priority_queue<int> mMaxHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> mMinHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */