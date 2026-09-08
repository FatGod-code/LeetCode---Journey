class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        std::unordered_map<std::string, int> wordTable;
        for (int idx = 0; idx<wordList.size(); ++idx)
        {
            wordTable[wordList[idx]] = idx;
        }

        if (wordTable.find(endWord)==wordTable.end()) { return 0; }
        if (wordTable.find(beginWord)==wordTable.end())
        {
            wordList.emplace_back(beginWord);
            wordTable[beginWord] = wordList.size()-1;
        }


        int results = 0;

        std::vector<bool> visited(wordList.size(), false);

        int beginIdx = wordTable[beginWord];
        
        std::queue<int> que;
        que.push(beginIdx);
        visited[beginIdx] = true;

        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto wordId = que.front();
                que.pop();

                if (wordList[wordId]==endWord) { return results+1; }

                std::string str = wordList[wordId];
                for (int l = 0; l<wordList[wordId].size(); ++l)
                {
                    unsigned char originalChar = wordList[wordId][l];
                    for (unsigned char c = 'a'; c<='z'; ++c)
                    {
                        if (originalChar==c) { continue; }

                        str[l] = c;
                        if (wordTable.find(str)!=wordTable.end() && !visited[wordTable[str]])
                        {
                            que.push(wordTable[str]);
                            visited[wordTable[str]] = true;
                        }
                    }

                    str[l] = originalChar;
                }
            }

            ++results;
        }

        //std::cout << results << std::endl;
        return 0;
    }
};

