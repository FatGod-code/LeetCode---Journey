class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.size()<s1.size()) { return false; }
        
        std::vector<int> table1(26);
        for (const auto ele : s1) { ++table1[ele-'a']; }

        std::vector<int> table2(26);
        for (int idx = 0; idx<s1.size(); ++idx) { ++table2[s2[idx]-'a']; }

        int numMatches = 0;
        for (int idx = 0; idx<table1.size(); ++idx)
        {
            if (table1[idx]==table2[idx]) { ++numMatches; }
        }

        if (numMatches==26) { return true; }

        for (int idx = 1; idx<s2.size()-s1.size()+1; ++idx)
        {
            char leftChar = s2[idx-1]-'a';
            if (table1[leftChar]==table2[leftChar]) { --numMatches; }
            --table2[leftChar];
            if (table1[leftChar]==table2[leftChar]) { ++numMatches; }
            
            char rightChar = s2[idx+s1.size()-1]-'a';
            if (table1[rightChar]==table2[rightChar]) { --numMatches; }
            ++table2[rightChar];
            if (table1[rightChar]==table2[rightChar]) { ++numMatches; }
            
            if (numMatches==26) { return true; }
        }

        return false;
    }
};