class Solution {
public:
    string minWindow(string s, string t)
    {
        std::vector<int> tableT(256, 0);
        for (const auto ele : t)
        {
            unsigned char idx = ele;
            ++tableT[idx];
        }

        int numRequiredMatch = 0;
        int numMatch = 0;
        std::vector<int> tableS(256, 0);
        for (int idx = 0; idx<tableT.size(); ++idx)
        {
            if (tableT[idx]==0) { continue; }
            ++numRequiredMatch;
        }

        int minLength = INT_MAX;
        
        int left = 0;
        int startPoint = 0;
        for (int right = 0; right<s.size(); ++right)
        {
            unsigned char idx = s[right];            
            ++tableS[idx];
            if (tableT[idx]!=0 && tableS[idx]==tableT[idx]) { ++numMatch;}

            while (numMatch==numRequiredMatch)
            {
                if (right-left+1<minLength)
                {
                    minLength = right-left+1;
                    startPoint = left;
                }

                unsigned char leftIdx = s[left];
                --tableS[leftIdx];
                if (tableT[leftIdx]!=0 && tableS[leftIdx]==tableT[leftIdx]-1) { --numMatch; }

                ++left;
            }
        }

        return minLength==INT_MAX ? "" : s.substr(startPoint, minLength);
    }
};