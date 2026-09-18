class Solution {
public:
    bool isHappy(int n)
    {
        int slow = n;
        int fast = countNext(n);

        while (fast!=1)
        {
            slow = countNext(slow);
            fast = countNext(fast);
            fast = countNext(fast);

            if (slow==fast) { return false;}
        }

        return true;
    }

private:
    int countNext(int x)
    {
        int value = 0;
        while (x)
        {
            int residue = x%10;
            value += (residue*residue);

            x /= 10;        
        }

        return value;
    }
};