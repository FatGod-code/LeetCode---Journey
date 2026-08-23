class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : mK(k)
    {
        for (const auto ele : nums)
        {
            if (mPQ.size()>=mK)
            {
                if (ele>mPQ.top())
                {
                    mPQ.pop();
                    mPQ.emplace(ele);
                }
            }
            else { mPQ.emplace(ele); }
            
        }
    }
    
    int add(int val)
    {
        if (mPQ.size()>=mK)
        {
            if (val>mPQ.top())
            {
                mPQ.pop();
                mPQ.emplace(val);
            }
        }
        else { mPQ.emplace(val); }

        return mPQ.top();
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> mPQ;
    int mK;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */