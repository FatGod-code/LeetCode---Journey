class Solution {
public:
    int numDecodings(string s)
    {
        int value1 = 1;
        int value2 = 1;
        for (int idx = 0; idx<s.size(); ++idx)
        {
            int results = 0;
            if (s[idx]!='0') { results += value2; }

            if (idx-1>=0 && s[idx-1]=='1') { results += value1; }
            else if (idx-1>=0 && s[idx-1]=='2' && s[idx]>='0' && s[idx]<='6') { results += value1; }

            value1 = value2;
            value2 = results;
        }

        return value2;
    }
};