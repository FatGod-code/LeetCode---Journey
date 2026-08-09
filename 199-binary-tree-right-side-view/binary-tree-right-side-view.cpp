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
    vector<int> rightSideView(TreeNode* root)
    {
        std::vector<int> results;
        (void) GetRightSideView(root, 1, results);

        return results;
    }

    TreeNode* GetRightSideView(TreeNode* root, int depth, std::vector<int>& results)
    {
        if (!root) { return nullptr; }

        if (depth>results.size()) { results.emplace_back(root->val); }

        auto right = GetRightSideView(root->right, depth+1, results);
        auto left = GetRightSideView(root->left, depth+1, results);

        return root;
    }
};