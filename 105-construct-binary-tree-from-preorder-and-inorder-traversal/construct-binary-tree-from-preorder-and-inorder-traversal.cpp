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
        for (int idx = 0; idx<inorder.size(); ++idx)
        {
            inorderIdxTable[inorder[idx]] = idx;
        }

        int idx = 0;
        TreeNode* root = nullptr;
        
        std::stack<std::pair<TreeNode**, std::pair<int, int>>> sta;
        sta.push({&root, {0, inorder.size()}});
        while (!sta.empty())
        {
            auto [node, p] = sta.top();
            auto [left, right] = p;
            sta.pop();

            if (left>=right) { continue; }

            int value = preorder[idx];
            ++idx;

            *node = new TreeNode(value);

            int inorderIdx = inorderIdxTable[value];

            sta.push({&(*node)->right, {inorderIdx+1, right}});
            sta.push({&(*node)->left, {left, inorderIdx}});
        }

        return root;
    }
};