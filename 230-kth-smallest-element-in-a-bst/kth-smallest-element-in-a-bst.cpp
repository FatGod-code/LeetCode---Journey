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
    int kthSmallest(TreeNode* root, int k)
    {
        if (!root) { return INT_MIN; }

        std::stack<std::pair<TreeNode*, bool>> sta;
        sta.push({root, true});
        while (!sta.empty())
        {
            auto [node, toPush] = sta.top();
            sta.pop();

            if (toPush)
            {
                if (node->right) { sta.push({node->right, true}); }
                sta.push({node, false});
                if (node->left) { sta.push({node->left, true}); }
            }
            else
            {
                --k;
                if (k==0) { return node->val; }
            }
        }

        return INT_MIN;
    }
};