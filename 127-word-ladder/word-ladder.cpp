class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        std::unordered_set<std::string> table(wordList.begin(), wordList.end());

        if (table.find(endWord)==table.end()) { return false; }
    
        int results = 0;

        std::string str;

        std::queue<std::string> que;
        que.push(beginWord);
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto word = que.front();
                que.pop();

                if (word==endWord) { return results+1; }

                for (int l = 0; l<word.size(); ++l)
                {
                    unsigned char originalChar = word[l];
                    for (unsigned char c = 'a'; c<='z'; ++c)
                    {
                        //if (c==originalChar) { continue; }

                        word[l] = c;
                        auto found = table.find(word);
                        if (found!=table.end())
                        {
                            que.push(word);
                            table.erase(found);
                        }
                    }

                    word[l] = originalChar;
                }
            }

            ++results;
        }


        return 0;

    }
};

