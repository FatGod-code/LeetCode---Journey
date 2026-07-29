class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int results = 0;

        std::unordered_set<int> table(nums.begin(), nums.end());
        while (!table.empty())
        {
            int value = *table.begin();
            table.erase(value);
            
            int length = 1;
            
            int valueL = value-1;
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
        }

        return results;
    }
};