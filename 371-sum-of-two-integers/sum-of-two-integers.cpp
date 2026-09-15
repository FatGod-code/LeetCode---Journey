class Solution {
public:
    int getSum(int a, int b)
    {   
        int results = 0;

        unsigned carry = 0;
        for (unsigned mask = 1u; mask!=0; mask = mask << 1)
        {
            unsigned digitA = (a & mask)!=0 ? 1u : 0;
            unsigned digitB = (b & mask)!=0 ? 1u : 0;

            unsigned sum = digitA^digitB^carry;
            if (sum) { results |= mask; }

            carry = (digitA & digitB) | (digitA & carry) | (digitB & carry);
        }

        return results;
    }
};