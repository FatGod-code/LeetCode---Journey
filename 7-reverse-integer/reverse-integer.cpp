class Solution {
public:
    int reverse(int x)
    {
        if (x==INT_MAX || x==INT_MIN) { return 0; }

        int results = 0;

        int limit = INT_MAX/10;
        std::cout << limit << std::endl;
        int value = std::abs(x);
        while (value)
        {
            int residue = value%10;
            if (results>limit)
            {
                std::cout << results;
                return 0;
            }
            if (results==limit)
            {
                if ((x<0 && residue>8) || (x>=0 && residue>7))
                {
                    return 0;
                }
            }
            
            
            results *= 10;
            results += residue;

            value /= 10;
        }

        return x>=0 ? results : -results;
    }
};