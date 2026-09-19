class Solution {
public:
    double myPow(double x, int n)
    {
        std::unordered_map<int, double> table;
        table[0] = 1;
        table[1] = x;
        table[-1] = 1/x;

        return countValue(x, n, table);
    }

    double countValue(double x, int n, std::unordered_map<int, double>& table)
    {
        if (table.find(n)!=table.end()) { return table[n]; }

        table[n] = countValue(x, n/2, table)*countValue(x, n/2+n%2, table);
        return table[n];
    }
};