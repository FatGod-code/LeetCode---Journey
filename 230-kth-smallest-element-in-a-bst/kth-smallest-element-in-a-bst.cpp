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
        return KthSmallestRecur(root, k)->val;
    }

    TreeNode* KthSmallestRecur(TreeNode* root, int& k)
    {
        if (!root) { return nullptr; }
        if (k==0) { return nullptr; }

        auto left = KthSmallestRecur(root->left, k);
        if (left) { return left; }

        --k;
        if (k==0) { return root; }
        
        auto right = KthSmallestRecur(root->right, k);

        return right;
    }
};