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
        return isBalancedRecur(root).first;
    }

    std::pair<bool, int> isBalancedRecur(TreeNode* root)
    {
        if (!root) { return {true, 0}; }

        auto left = isBalancedRecur(root->left);
        auto right = isBalancedRecur(root->right);

        if (!left.first || !right.first) { return {false, -1}; }

        auto leftHeight = left.second;
        auto rightHeight = right.second;
        int difference = std::abs(leftHeight-rightHeight);

        if (difference>1) { return {false, -1}; }

        return {true, std::max(leftHeight, rightHeight)+1};
    }
};