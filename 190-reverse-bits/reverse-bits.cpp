class Solution {
public:
    int reverseBits(int n)
    {
        int results = 0;

        unsigned leftMask = 1 << 31;
        unsigned rightMask = 1;
        for (int idx = 0; idx<16; ++idx)
        {
            bool isLeftOne = (n & leftMask)!=0;
            bool isRightOne = (n & rightMask)!=0;

            if (isLeftOne) { results |= rightMask; }
            if (isRightOne) { results |= leftMask; }

            leftMask = leftMask >> 1;
            rightMask = rightMask << 1;
        }

        return results;
    }
};