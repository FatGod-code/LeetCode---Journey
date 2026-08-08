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
    int maxDepth(TreeNode* root)
    {
        if (!root) { return 0; }

        int maxHeight = 0;
        std::stack<std::pair<TreeNode*, int>> sta;
        sta.push({root, 1});
        while (!sta.empty())
        {
            auto top = sta.top();
            auto node = top.first;
            auto height = top.second;
            sta.pop();

            maxHeight = std::max(height, maxHeight);

            if (node->right) { sta.push({node->right, height+1}); }
            if (node->left) { sta.push({node->left, height+1}); }
        }

        return maxHeight;
    }
};