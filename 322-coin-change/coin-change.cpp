class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        std::vector<int> table(amount+1, INT_MAX);
        table[0] = 0;

        for (int idx = 1; idx<table.size(); ++idx)
        {
            for (const auto& coin : coins)
            {
                if (idx-coin<0) { continue; }
                if (table[idx-coin]==INT_MAX) { continue; }

                table[idx] = std::min(table[idx-coin]+1, table[idx]);
            }
        }

        return table.back()==INT_MAX ? -1 : table.back();
    }
};