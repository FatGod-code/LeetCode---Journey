class Solution {
public:
    int countSubstrings(string s)
    {
        std::vector<bool> table(s.size(), false);

        int results = 0;
        for (int i = s.size()-1; i>=0; --i)
        {
            for (int j = s.size()-1; j>=i; --j)
            {
                if (j-i+1<=2 && s[i]==s[j])
                {
                    table[j] = true;
                    ++results;
                }
                else if (s[j]==s[i] && table[j-1])
                {
                    table[j] = true;
                    ++results;
                }
                else { table[j] = false; }
            }
        }

        return results;
    }
};