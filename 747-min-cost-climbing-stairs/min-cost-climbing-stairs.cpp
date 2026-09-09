class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {

        int value1 = 0;
        int value2 = 0;
        int results = 0;
        for (int idx = 2; idx<=cost.size(); ++idx)
        {
            results = std::min(cost[idx-2]+value1, cost[idx-1]+value2);
            value1 = value2;
            value2 = results;
        }

        return results;


    }
    
};