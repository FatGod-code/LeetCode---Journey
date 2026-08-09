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
    bool isBalanced(TreeNode* root)
    {
        auto value = isBalancedRecur(root);
        return value==-1 ? false : true;
    }

    int isBalancedRecur(TreeNode* root)
    {
        if (!root) { return 0; }

        auto left = isBalancedRecur(root->left);
        if (left==-1) { return -1; }

        auto right = isBalancedRecur(root->right);
        if (right==-1) { return -1; }
        
        int difference = std::abs(left-right);

        if (difference>1) { return -1; }
        return std::max(left, right)+1;
    }
};