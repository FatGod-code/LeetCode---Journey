class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        wordList.emplace_back(beginWord);
        std::vector<bool> visited(wordList.size(), false);

        int results = 0;

        std::queue<int> que;
        que.push(wordList.size()-1);
        visited[wordList.size()-1] = true;
        
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto wordId = que.front();
                que.pop();

                if (wordList[wordId]==endWord) { return results+1; }

                std::vector<int> neighbors;
                FindNeighbors(wordList, wordId, neighbors);
                for (const auto ele : neighbors)
                {
                    if (visited[ele]) { continue; }

                    que.push(ele);
                    visited[ele] = true;
                }
            }

            ++results;
        }

        return 0;
    }

    bool isOnly1Difference(const std::string& candidate, const std::string& target)
    {
        int numDifference = 0;
        for (int idx = 0; idx<candidate.size(); ++idx)
        {
            if (candidate[idx]^target[idx]) { ++numDifference;}
        }

        return numDifference==1 ? true : false;
    }
    
    void FindNeighbors(const std::vector<std::string>& wordList, int wordId,
                       std::vector<int>& neighbors)
    {
        for (int idx = 0; idx<wordList.size(); ++idx)
        {
            if (isOnly1Difference(wordList[idx], wordList[wordId])) { neighbors.emplace_back(idx); }
        }
    }
};

