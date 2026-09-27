class Solution {
public:
    int numDistinct(string s, string t)
    {
        std::vector<unsigned> table(t.size()+1, 0);
        table[0] = 1;
        for (int idx = 0; idx<t.size(); ++idx) { table[idx+1] = 0; }

        for (int idx1 = 0; idx1<s.size(); ++idx1)
        {
            unsigned previous = table[0];
            for (int idx2 = 0; idx2<t.size(); ++idx2)
            {
                unsigned temp = table[idx2+1];
                if (s[idx1]==t[idx2]) { table[idx2+1] = previous+temp; }
                else { table[idx2+1] = temp; }

                previous = temp;
            }
        }

        return table.back();
    }
};