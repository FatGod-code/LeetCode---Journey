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
                if (idx+1-static_cast<int>(word.size())<0) { continue; }

                if (!table[idx+1-word.size()]) { continue; }

                if (word==s.substr(idx+1-word.size(), word.size())) { table[idx+1] = true; };
            }
        }

        return table.back();
    }
};