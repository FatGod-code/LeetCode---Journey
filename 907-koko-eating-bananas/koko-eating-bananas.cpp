class Solution {
public:
    bool Decision(const std::vector<int>& piles, int h, int speed)
    {
        int needHours = 0;
        for (const auto ele : piles)
        {
            needHours += ((ele/speed)+(ele%speed ? 1 : 0));
        }

        return h>=needHours;
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