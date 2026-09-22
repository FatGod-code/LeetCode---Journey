class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        std::vector<unsigned long long> table(amount+1, 0);
        table.front() = 1;

        int size = static_cast<int>(table.size());
        for (const auto ele : coins)
        {
            for (int idx = 1; idx<size; ++idx)
            {
                if (idx-ele<0) { continue; }
                
                table[idx] += table[idx-ele];
            }
        }

        return table.back();
    }
};