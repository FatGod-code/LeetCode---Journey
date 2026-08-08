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
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root) { return nullptr; }

        std::queue<TreeNode*> que;
        que.emplace(root);
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto node = que.front();
                que.pop();

                std::swap(node->left, node->right);

                if (node->left) { que.emplace(node->left); }
                if (node->right) { que.emplace(node->right); }
            }
        }

        return root;
    }
};