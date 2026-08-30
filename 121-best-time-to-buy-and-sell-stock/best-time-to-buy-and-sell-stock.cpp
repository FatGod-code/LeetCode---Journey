class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (const auto ele : prices)
        {
            if (ele>minPrice)
            {
                int profit = ele-minPrice;
                maxProfit = std::max(profit, maxProfit);
            }
            else { minPrice = ele; }
        }

        return maxProfit;
    }
};