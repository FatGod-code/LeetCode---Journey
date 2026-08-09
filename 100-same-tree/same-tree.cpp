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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p || !q) { return p==q; }

        std::queue<std::pair<TreeNode*, TreeNode*>> que;
        que.push({p, q});
        while (!que.empty())
        {
            int size = que.size();
            for (int s = 0; s<size; ++s)
            {
                auto [node1, node2] = que.front();
                que.pop();
                
                
                if (node1->val!=node2->val) { return false; }

                if (node1->left && node2->left) { que.push({node1->left, node2->left}); }
                else if (node1->left || node2->left) { return false; }

                if (node1->right && node2->right) { que.push({node1->right, node2->right}); }
                else if (node1->right || node2->right) { return false; }
            }
        }

        return true;
    }
};