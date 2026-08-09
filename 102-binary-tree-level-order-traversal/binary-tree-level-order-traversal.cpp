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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> results;
        GetLevelOrder(root, 1, results);

        return results;
    }

    void GetLevelOrder(TreeNode* root, int height, std::vector<std::vector<int>>& results)
    {
        if (!root) { return; }

        if (height>results.size()) { results.push_back({}); }

        results[height-1].emplace_back(root->val);

        GetLevelOrder(root->left, height+1, results);
        GetLevelOrder(root->right, height+1, results);
    }
};