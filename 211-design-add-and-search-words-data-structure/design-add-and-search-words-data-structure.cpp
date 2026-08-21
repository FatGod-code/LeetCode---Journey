struct TrieNode
{
    TrieNode() = default;
    ~TrieNode() = default;

    TrieNode* children[26]{};
    bool isEnd{false};
};

class WordDictionary {
public:
    WordDictionary()
    {
        mRoot = new TrieNode();
    }
    
    void addWord(string word)
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
    
    bool search(string word)
    {
        return Find(word, 0, mRoot);
    }

private:
    TrieNode* mRoot{nullptr};

    bool Find(const std::string& str, int idx, TrieNode* node)
    {
        if (!node) { return false; }
        if (idx==str.size()-1)
        {
            char ch = str[idx];
            if (ch!='.')
            {
                int cidx = ch - 'a';
                if (node->children[cidx] && node->children[cidx]->isEnd) { return true; }
                else { return false; }
            }
            else
            {
                const auto& children = node->children;
                for (const auto& child : children)
                {
                   if (child && child->isEnd) { return  true; }
                }

                return false;
            }
        }

        if (str[idx]=='.')
        {
            for (const auto& child : node->children)
            {
                if (!child) { continue; }
                if (Find(str, idx+1, child)) { return true; }
            }

            return false;
        }

        int cidx = str[idx]-'a';
        if (!node->children[cidx]) { return false; }
        
        return Find(str, idx+1, node->children[cidx]);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */