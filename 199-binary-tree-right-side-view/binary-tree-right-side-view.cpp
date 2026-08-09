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
    vector<int> rightSideView(TreeNode* root)
    {
        if (!root) { return {}; }

        std::vector<int> results;

        std::queue<TreeNode*> que;
        que.emplace(root); 
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto front = que.front();
                que.pop();

                if (s==size-1) { results.emplace_back(front->val); }

                if (front->left) { que.emplace(front->left); }
                if (front->right) { que.emplace(front->right); }
            }
        }

        return results;
    }
};