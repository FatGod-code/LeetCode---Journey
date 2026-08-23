struct TrieNode
{
    TrieNode() = default;
    ~TrieNode() = default;

    std::array<TrieNode*, 26> children{};
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

        std::string str;
        std::vector<std::string> results;
        for (int row = 0; row<board.size(); ++row)
        {
            for (int col = 0; col<board[0].size(); ++col)
            {
                FindWord(board, row, col, trie.getRoot(), str, results);
            }
        }

        return results;
    }

    void FindWord(std::vector<std::vector<char>>& board, int row, int col,
                  TrieNode* trieNode, std::string& str, std::vector<std::string>& results)
    {
        if (row<0 || row>=board.size() || col<0 || col>=board[0].size()) { return; }
        if (board[row][col]=='#') { return; }
        //if (!trieNode) { return; }

        int idx = board[row][col]-'a';
        auto child = trieNode->children[idx];
        if (!child) { return; }

        str += board[row][col];
        if (child->isEnd)
        {
            results.emplace_back(str);
            child->isEnd = false;
        }

        auto temp = board[row][col];
        board[row][col] = '#';

        FindWord(board, row-1, col, child, str, results);
        FindWord(board, row+1, col, child, str, results);
        
        FindWord(board, row, col-1, child, str, results);
        FindWord(board, row, col+1, child, str, results);

        str.pop_back();
        board[row][col] = temp;
    }
};