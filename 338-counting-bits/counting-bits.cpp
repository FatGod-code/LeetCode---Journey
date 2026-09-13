class Solution {
public:
    vector<int> countBits(int n)
    {
        std::vector<int> results(n+1, 0);
        for (int idx = 0; idx<=n; ++idx)
        {
            int value = idx>>1;
            int residue = idx&1;
            results[idx] = results[value]+residue;
        }

        return results;
    }
};