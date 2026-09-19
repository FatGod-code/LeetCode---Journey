class Solution {
public:
    double myPow(double x, int n)
    {
        long long N = static_cast<long long>(n);
        N = std::abs(N);
        std::cout << N << std::endl;
        double results = 1.0;
        
        double value = x;
        unsigned long long mask = 1u;
        for (int idx = 0; idx<32; ++idx)
        {
            bool is1 = (N & mask)!=0;
            if (is1) { results *= value; std::cout << "fuck"; }

            mask = mask << 1;
            value *= value;
        }
    
        return n>=0 ? results : 1/results;
    }
};