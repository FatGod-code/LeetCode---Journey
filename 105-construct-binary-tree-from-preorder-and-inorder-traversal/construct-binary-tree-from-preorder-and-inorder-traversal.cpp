/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        std::unordered_map<int, int> inorderIdxTable;
        for(int idx = 0; idx<inorder.size(); ++idx)
        {
            inorderIdxTable.emplace(inorder[idx], idx);
        }

        TreeNode* root = nullptr;
        int idx = 0;
        GenerateTreeNodes(preorder, inorder, inorderIdxTable, root, idx, 0, preorder.size());

        return root;
    }

    void GenerateTreeNodes(const std::vector<int>&preorder, const std::vector<int>& inorder,
                           const std::unordered_map<int, int>& inorderIdxTable,
                           TreeNode*& root, int& idx, int start, int end)
    {
        if (start>=end) { return; }
        if (idx>=preorder.size()) { return; }

        int value = preorder[idx];
        root = new TreeNode(value);
        ++idx;
        
        auto inorderIdx = inorderIdxTable.at(value);
        GenerateTreeNodes(preorder, inorder, inorderIdxTable, root->left, idx, start, inorderIdx);
        GenerateTreeNodes(preorder, inorder, inorderIdxTable, root->right, idx, inorderIdx+1, end);
    }
};