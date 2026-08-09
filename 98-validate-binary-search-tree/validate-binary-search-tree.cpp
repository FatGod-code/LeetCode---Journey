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
        return IsBinaryTreeBST(root, nullptr, nullptr);
    }

    bool IsBinaryTreeBST(TreeNode* root, TreeNode* leftBound, TreeNode* rightBound)
    {
        if (!root) { return true; }
        
        if ((leftBound && leftBound->val>=root->val) ||
            (rightBound && rightBound->val<=root->val)) { return false; }

        int value = root->val;
        return IsBinaryTreeBST(root->left, leftBound, root) && IsBinaryTreeBST(root->right, root, rightBound);
    }
};