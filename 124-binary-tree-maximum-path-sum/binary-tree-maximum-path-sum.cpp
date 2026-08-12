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
    int maxPathSum(TreeNode* root)
    {
        if (!root) { return 0; }

        int results = INT_MIN;

        std::unordered_map<TreeNode*, int> table;
        std::stack<std::pair<TreeNode*, bool>> sta;
        sta.push({root, true});
        while (!sta.empty())
        {
            auto [node, toPush] = sta.top();
            sta.pop();

            if (toPush)
            {
                sta.push({node, false});
                
                if (node->right) { sta.push({node->right, true}); }
                if (node->left) { sta.push({node->left, true}); }
            }
            else
            {
                auto left = std::max(0, table[node->left]);
                auto right = std::max(0, table[node->right]);

                int sum = node->val+left+right;
                results = std::max(sum, results);

                table[node] = std::max(node->val+left, node->val+right);

                table.erase(node->left);
                table.erase(node->right);
            }
        }

        return results;
    }
};