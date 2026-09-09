class Solution {
public:
    int climbStairs(int n)
    {
        std::vector<int> table(n+1, -1);

        return CountNumClimbing(n, table);
    }

    int CountNumClimbing(int n, std::vector<int>& table)
    {
        if (n==1 || n==2) { return n; }

        if (table[n]!=-1) { return table[n]; }

        table[n] = CountNumClimbing(n-1, table)+CountNumClimbing(n-2, table);
        return table[n];
    }
};