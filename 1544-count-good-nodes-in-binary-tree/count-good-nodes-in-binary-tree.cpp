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
    int goodNodes(TreeNode* root)
    {
        if (!root) { return 0; }

        int results = 0;

        std::stack<std::pair<TreeNode*, TreeNode*>> sta;
        sta.push({root, nullptr});
        while (!sta.empty())
        {
            auto [node, maxNode] = sta.top();
            sta.pop();

            if (!maxNode || node->val>=maxNode->val)
            {
                ++results;
                maxNode = node;
            }

            if (node->right) { sta.push({node->right, maxNode}); }
            if (node->left) { sta.push({node->left, maxNode}); }
        }

        return results;
    }
};