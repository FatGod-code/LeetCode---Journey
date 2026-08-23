struct TrieNode
{
    TrieNode() = default;
    ~TrieNode() = default;

    std::array<TrieNode*, 26> children{};
    std::string word;
    bool isEnd{false};
};

class Trie
{
public:
    Trie() { mRoot = new TrieNode(); }

    void addWord(const std::string& word)
    {
        auto root = mRoot;
        for (const auto ele : word)
        {
            int idx = ele-'a';
            auto& child = root->children[idx];
            if (!child) { child = new TrieNode(); }

            root = child;
        }

        root->word = word;
        root->isEnd = true;
    }

    TrieNode* getRoot() { return mRoot; }

private:
    TrieNode* mRoot{nullptr};
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        Trie trie;
        for (const auto& ele : words) { trie.addWord(ele); }

        std::vector<std::string> results;
        for (int row = 0; row<board.size(); ++row)
        {
            for (int col = 0; col<board[0].size(); ++col)
            {
                FindWord(board, row, col, trie.getRoot(), results);
            }
        }

        return results;
    }

    void FindWord(std::vector<std::vector<char>>& board, int row, int col,
                  TrieNode* trieNode, std::vector<std::string>& results)
    {
        if (row<0 || row>=board.size() || col<0 || col>=board[0].size()) { return; }
        if (board[row][col]=='#') { return; }
        if (!trieNode) { return; }

        int idx = board[row][col]-'a';
        auto& child = trieNode->children[idx];
        if (!child) { return; }

        if (child->isEnd)
        {
            results.emplace_back(child->word);
            child->isEnd = false;
            child->word.clear();
        }

        auto temp = board[row][col];
        board[row][col] = '#';

        FindWord(board, row-1, col, child, results);
        FindWord(board, row+1, col, child, results);
        
        FindWord(board, row, col-1, child, results);
        FindWord(board, row, col+1, child, results);

        board[row][col] = temp;

        if (CanDelete(child))
        {
            delete child;
            child = nullptr;
        }
    }

    bool CanDelete(TrieNode* node)
    {
        if (!node) { return false; }

        if (!node->word.empty()) { return false; }
        if (node->isEnd) { return false; }

        for (const auto child : node->children)
        {
            if (child) { return false; }
        }

        return true;
    }
};