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

        int maxPathSum = INT_MIN;
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
                
                if (node->left) { sta.push({node->left, true}); }
                if (node->right) { sta.push({node->right, true}); }
            }
            else
            {
                int left = std::max(0, table[node->left]);
                int right = std::max(0, table[node->right]);

                int pathSum = node->val+left+right;
                maxPathSum = std::max(pathSum, maxPathSum);

                table[node] = node->val+std::max(left, right);

                table.erase(node->left);
                table.erase(node->right);
            }
        }

        return maxPathSum;
    }
};