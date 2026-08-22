struct TrieNode
{
    TrieNode() = default;
    ~TrieNode() = default;

    std::array<TrieNode*, 26> children{};
    bool isEnd{false};
};

class WordDictionary {
public:
    WordDictionary() { mRoot = new TrieNode(); }
    
    void addWord(const string& word)
    {
        auto root = mRoot;
        for (const auto ele : word)
        {
            int idx = ele-'a';
            auto& child = root->children[idx];
            if (!child) { child = new TrieNode(); }

            root = child;
        }

        root->isEnd = true;
    }
    
    bool search(const string& word)
    {
        //return FindWord(word, 0, mRoot);

        if (word.empty()) { return false; }

        std::stack<std::pair<int, TrieNode*>> sta;
        sta.push({0, mRoot});
        while (!sta.empty())
        {
            auto [idx, root] = sta.top();
            sta.pop();

            if (!root) { continue; }
            if (idx==word.size())
            {
                if (root->isEnd) { return true;}
                continue;
            }

            if (word[idx]=='.')
            {
                for (const auto child : root->children)
                {
                    sta.push({idx+1, child});
                }
            }
            else
            {
                int cidx = word[idx]-'a';
                sta.push({idx+1, root->children[cidx]});
            }
        }

        return false;
    }

private:
    TrieNode* mRoot{nullptr};

    bool FindWord(const std::string& word, int idx, TrieNode* root)
    {
        if (!root) { return false; }
        if (idx==word.size()) { return root->isEnd; }

        if (word[idx]=='.')
        {
            for (const auto child : root->children)
            {
                if (FindWord(word, idx+1, child)) { return true;}
            }

            return false;
        }

        int cidx = word[idx]-'a';
        return FindWord(word, idx+1, root->children[cidx]);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */