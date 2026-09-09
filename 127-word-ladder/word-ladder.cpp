class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        std::unordered_set<std::string> table(wordList.begin(), wordList.end());
        if (table.find(endWord)==table.end()) { return 0;}

        int results = 1;

        std::string str;

        std::queue<std::string> que;
        que.push(beginWord);
        //if (table.find(beginWord)!=table.end()) { table.erase(beginWord); }

        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto word = que.front();
                que.pop();

                if (word==endWord) { return results; }

                str = word;
                for (int l = 0; l<word.size(); ++l)
                {
                    unsigned char originalChar = str[l];
                    for (unsigned char c  = 'a'; c<='z'; ++c)
                    {
                        str[l] = c;
                        auto found = table.find(str);
                        if (found!=table.end())
                        {
                            que.push(str);
                            table.erase(found);
                        }
                    }
                    
                    str[l] = originalChar;
                }
            }

            ++results;
        }

        return 0;
    }
};

