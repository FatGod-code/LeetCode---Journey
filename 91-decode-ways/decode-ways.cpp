class Solution {
public:
    int numDecodings(string s)
    {
        if (s[0]==0) { return 0; }

        std::vector<int> table(s.size()+1);
        table[0] = 1;
        for (int idx = 0; idx<s.size(); ++idx)
        {
            if (s[idx]!='0') { table[idx+1] += table[idx]; }
            
            if (idx-1>=0 && s[idx-1]=='1') { table[idx+1] += table[idx-1]; }
            else if (idx-1>=0 && s[idx-1]=='2' && s[idx]<='6' && s[idx]>='0') { table[idx+1] += table[idx-1]; }

            if (table[idx+1]==0 && table[idx]==0) { return 0; }
        }

        return table.back();
    }
};