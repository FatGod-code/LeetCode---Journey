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
        if (!root) { INT_MIN; }

        std::stack<TreeNode*> sta;
        TreeNode* current = root;
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
            if (k==0) { return node->val; }

            current = node->right;
        }

        return INT_MIN;
    }
};