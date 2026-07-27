class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int results = 0;

        std::set<int> table(nums.begin(), nums.end());
        for (auto citr = table.cbegin(); citr!= table.cend(); ++citr)
        {
            int length = 1;
            while (citr!=table.cend())
            {
                auto found = table.find(*citr+1);
                if (found==table.cend()) { break; }

                ++length;
                ++citr;
            }

            results = std::max(length, results);
        }

        return results;
    }
};