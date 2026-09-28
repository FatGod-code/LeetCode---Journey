class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty()) { return 0; }
        
        int preHold = -prices[0];
        int hold = 0;
        
        int preSold = 0;
        int sold = 0;

        int preRest = 0;
        int rest = 0;

        for (int idx = 1; idx<prices.size(); ++idx)
        {
            hold = std::max(preHold, preRest-prices[idx]);
            sold = preHold+prices[idx];
            rest = std::max(preRest, preSold);
            
            preHold = hold;
            preSold = sold;
            preRest = rest;
        }

        return std::max({hold, sold, rest});
    }
};