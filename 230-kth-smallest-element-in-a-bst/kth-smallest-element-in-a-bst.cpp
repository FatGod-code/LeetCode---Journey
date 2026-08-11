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

        std::stack<TreeNode*> sta;
        TreeNode* current = root;
        TreeNode* results = nullptr;
        while (current || !sta.empty())
        {
            while (current)
            {
                sta.emplace(current);
                current = current->left;
            }

            auto node = sta.top();
            sta.pop();

            --k;
            if (k==0)
            {
                results = node;
                break;
            }

            current = node->right;
        }

        if (k!=0) { return INT_MIN; }
        return results->val;
    }
};