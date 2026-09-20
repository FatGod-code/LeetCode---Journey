class Solution {
public:
    int reverseDegree(string s)
    {
        int results = 0;
        for (int idx = 0; idx<s.size(); ++idx) { results += (idx+1)*(26-(s[idx]-'a')); }

        return results;
    }
};