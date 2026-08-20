struct TrieNode
{
    TrieNode() = default;

    std::array<TrieNode*, 26> children{};
    bool isEnd{false};
};

class Trie {
public:
    Trie()　{　mRoot = new TrieNode;　}

    Trie(const Trie& trie) = delete;
    Trie& operator=(const Trie& trie) = delete;

    ~Trie()
    {
        if (!mRoot) { return; }
        
        std::stack<TrieNode*>sta;
        sta.emplace(mRoot);
        while (!sta.empty())
        {
            auto ptr = sta.top();
            sta.pop();

            for (const auto ele : ptr->children)
            {
                if (ele) { sta.emplace(ele); }
            }

            delete ptr;
        }
    }
    
    void insert(const string& word)
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
    
    bool search(const string& word)
    {
        auto node = FindString(word);
        return node ? node->isEnd : false; 
    }
    
    bool startsWith(const string& prefix)
    {
        return FindString(prefix);
    }

private:
    TrieNode* mRoot{nullptr};

    TrieNode* FindString(const std::string& str)
    {
        auto root = mRoot;
        for (const auto ele : str)
        {
            int idx = ele-'a';
            const auto child = root->children[idx];
            if (!child) { return nullptr; }

            root = child;
        }

        return root;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */