class Solution {
public:
    int reverseBits(int n)
    {
        int results = 0;

        unsigned leftMask = 1u << 31;
        unsigned rightMask = 1u;
        for (int idx = 0; idx<16; ++idx)
        {
            bool isLeft1 = (n & leftMask)!=0;
            bool isRight1 = (n & rightMask)!=0;

            if (isLeft1) { results |= rightMask; }
            if (isRight1) { results |= leftMask; }

            leftMask = leftMask >> 1;
            rightMask = rightMask << 1;
        }

        return results;
    }
};