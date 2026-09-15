class Solution {
public:
    int reverse(int x)
    {
        int results = 0;

        int maxLimit = INT_MAX/10;
        int maxResidue = INT_MAX%10;

        int minLimit = INT_MIN/10;
        int minResidue = INT_MIN%10;

        while (x)
        {
            int residue = x%10;

            if (results>maxLimit) { return 0; }
            if (results==maxLimit && residue>maxResidue) { return 0; }

            if (results<minLimit) { return 0; }
            if (results==minLimit && residue<minResidue) { return 0; }

            results *= 10;
            results += residue;

            x /= 10;
        }

        return results;
    }
};