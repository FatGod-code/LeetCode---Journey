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
    bool isValidBST(TreeNode* root)
    {
        return IsBinaryTreeBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool IsBinaryTreeBST(TreeNode* root, long long leftBound, long long rightBound)
    {
        if (!root) { return true; }
        
        if (leftBound>=root->val || rightBound<=root->val) { return false; }

        int value = root->val;
        return IsBinaryTreeBST(root->left, leftBound, value) && IsBinaryTreeBST(root->right, value, rightBound);
    }
};