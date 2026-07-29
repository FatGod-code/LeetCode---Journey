class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int results = 0;

        std::unordered_set<int> table(nums.begin(), nums.end());
        while (!table.empty())
        {
            int value = *table.begin();
            int valueL = value-1;
            int length = 1;
            while (table.find(valueL)!=table.end())
            {
                ++length;
                table.erase(valueL);
                --valueL;
            }

            int valueR = value+1;
            while (table.find(valueR)!=table.end())
            {
                ++length;
                table.erase(valueR);
                ++valueR;
            }

            results = std::max(length, results);
            table.erase(value);
        }

        return results;
    }
};