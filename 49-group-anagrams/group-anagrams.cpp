class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        std::vector<std::vector<std::string>> results;
        
        std::unordered_map<std::string, int> indexTable;
        for (int idx = 0; idx<strs.size(); ++idx)
        {
            std::string str = strs[idx];
            std::sort(str.begin(), str.end());

            auto found = indexTable.find(str);
            if (found!=indexTable.end()) { results[found->second].emplace_back(strs[idx]); }
            else
            {
                indexTable.emplace(str, results.size());
                results.emplace_back(1, strs[idx]);
            }
        }

        return results;
    }
};