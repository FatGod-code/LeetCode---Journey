class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty()) { return 0; }

        std::vector<int> hold(prices.size());
        hold[0] = -prices[0];
        
        std::vector<int> sold(prices.size(), 0);
        std::vector<int> rest(prices.size(), 0);

        for (int idx = 1; idx<prices.size(); ++idx)
        {
            hold[idx] = std::max(hold[idx-1], rest[idx-1]-prices[idx]);
            sold[idx] = hold[idx-1]+prices[idx];
            rest[idx] = std::max(rest[idx-1], sold[idx-1]);
        }

        return std::max({hold.back(), sold.back(), rest.back()});
    }
};