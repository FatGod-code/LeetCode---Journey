class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty()) { return 0; }

        int hold = -prices[0];
        int sold = 0;
        int rest = 0;
        for (int idx = 1; idx<prices.size(); ++idx)
        {
            int preHold = hold;
            int preSold = sold;
            int preRest = rest;

            hold = std::max(preHold, preRest-prices[idx]);
            sold = preHold+prices[idx];
            rest = std::max(preRest, preSold);
        }

        return std::max({hold, sold, rest});
    }
};