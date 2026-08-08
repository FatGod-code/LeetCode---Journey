class Solution {
public:
    bool Decision(const std::vector<int>& piles, int h, int speed)
    {
        int idx = 0;
        while (h>0)
        {
            if (idx==piles.size()) { return true; }
            
            int numBananas = piles[idx];
            int needHours = (numBananas/speed)+((numBananas%speed) ? 1 : 0);
            
            h -= needHours;
            ++idx;
        }

        return (h>=0 && idx==piles.size()) ? true : false;
    }

    int minEatingSpeed(vector<int>& piles, int h)
    {
        int maxBananas = 0;
        for (const auto ele : piles) { maxBananas = std::max(ele, maxBananas); }

        int left = 1;
        int right = maxBananas+1;
        while (left<right)
        {
            int middle = left+(right-left)/2;

            if (Decision(piles, h, middle)) { right = middle; }
            else { left = middle+1; }
        }

        return left;
    }
};