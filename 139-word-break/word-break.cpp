class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        std::vector<bool> table(s.size()+1, false);
        table[0] = true;

        for (int idx = 0; idx<s.size(); ++idx)
        {
            for (const auto& word : wordDict)
            {
                int wordLength = static_cast<int>(word.size());
                int index = idx+1-wordLength;
                if (index<0) { continue; }

                if (!table[index]) { continue; }

                if (s.compare(index, wordLength, word)==0)
                {
                    table[idx+1] = true;
                    break;
                }
            }
        }

        return table.back();
    }
};