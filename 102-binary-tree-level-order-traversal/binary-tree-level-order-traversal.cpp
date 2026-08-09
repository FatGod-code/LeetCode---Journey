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
        if (!root) { return {}; }

        std::vector<std::vector<int>> results;

        std::queue<TreeNode*> que;
        que.emplace(root);
        while (!que.empty())
        {
            int size = que.size();
            std::vector<int> levelOrder(size);
            
            
            for (int s = 0; s<size; ++s)
            {
                auto front = que.front();
                que.pop();

                levelOrder[s] = front->val;

                if (front->left) { que.emplace(front->left); }
                if (front->right) { que.emplace(front->right); }
            }

            results.emplace_back(levelOrder);
        }

        return results;
    }
};