class Solution {
public:
    int reverse(int x)
    {
        if (x==INT_MIN || x==INT_MAX) { return 0; }

        int results = 0;

        int limit = INT_MAX/10;
        int value = std::abs(x);
        while (value)
        {
            int residue = value%10;

            if (results>limit) { return 0; }
            if (results==limit)
            {
                if ((x<0 && residue>8) || (x>=0 && residue>7)) { return 0; }
            }
            
            results *= 10;
            results += residue;

            value /= 10;
        }

        return x>=0 ? results : -results;
    }
};