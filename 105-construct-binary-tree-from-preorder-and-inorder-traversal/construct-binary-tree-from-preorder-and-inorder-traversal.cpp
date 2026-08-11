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
        for (int idx = 0; idx<inorder.size(); ++idx) { mTable[inorder[idx]] = idx; }

        TreeNode* results = nullptr;
        GenerateNode(preorder, results, 0, inorder.size());
        return results;
    }

    void GenerateNode(const std::vector<int> &preorder, TreeNode* &ptr, int left, int right)
    {
        if (mIdx>=preorder.size()) { return; }
        if (left>=right) { return; }

        int value = preorder[mIdx++];
        ptr = new TreeNode(value);
        
        int idx = mTable[value];
        GenerateNode(preorder, ptr->left, left, idx);
        GenerateNode(preorder, ptr->right, idx+1, right);
    }

private:
    int mIdx{0};
    std::unordered_map<int, int> mTable;
};