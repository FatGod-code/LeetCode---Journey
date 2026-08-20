struct TrieNode
{
    TrieNode() :children(26, nullptr) {}

    std::vector<TrieNode*> children;
    bool isEnd{false};
};

class Trie {
public:
    Trie()
    {
        mRoot = new TrieNode;
    }
    
    void insert(string word)
    {
        auto root = mRoot;
        for (const auto ele : word)
        {
            int idx = ele-'a';
            auto& child = root->children[idx];
            if (!child) { child = new TrieNode; }

            root = child;
        }
        root->isEnd = true;
    }
    
    bool search(string word)
    {
        auto root = mRoot;
        for (const auto ele : word)
        {
            int idx = ele-'a';
            const auto child = root->children[idx];
            if (!child) { return false;}

            root = child;
        }

        return root->isEnd;
    }
    
    bool startsWith(string prefix)
    {
        auto root = mRoot;
        for (const auto ele : prefix)
        {
            int idx = ele-'a';
            const auto child = root->children[idx];
            if (!child) { return false; }

            root = child;
        }

        return true;
    }

private:
    TrieNode* mRoot{nullptr};
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */