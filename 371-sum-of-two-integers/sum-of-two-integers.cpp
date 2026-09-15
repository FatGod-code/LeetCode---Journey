class Solution {
public:
    int getSum(int a, int b)
    {
        std::vector<int> count(32);

        int results = 0;

        unsigned carry = 0;
        unsigned mask = 1u;
        for (const auto ele : count)
        {
            unsigned digitA = (a & mask)!=0 ? 1u : 0;
            unsigned digitB = (b & mask)!=0 ? 1u : 0;

            unsigned sum = digitA^digitB^carry;
            if (sum) { results |= mask; }

            carry = (digitA & digitB) | (digitA & carry) | (digitB & carry);
            mask = mask << 1;
        }

        return results;
    }
};