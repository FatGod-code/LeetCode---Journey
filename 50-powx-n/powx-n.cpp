class Solution {
public:
    double myPow(double x, int n)
    {
        long long N = static_cast<long long>(n);
        N = std::abs(N);

        double results = 1;
        double value = x;
        unsigned mask = 1u;
        for (int idx = 0; idx<32; ++idx)
        {
            bool is1 = (N & mask)!=0;
            if (is1) { results *= value; }

            mask = mask << 1;
            value *= value;
        }
        
        return n>=0 ? results : 1/results;
    }
};