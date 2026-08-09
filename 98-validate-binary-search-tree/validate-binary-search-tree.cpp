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
        TreeNode* bound = nullptr;
        return IsBinaryTreeBST(root, bound);
    }

    bool IsBinaryTreeBST(TreeNode* root, TreeNode*& bound)
    {
        if (!root) { return true; }
        
        auto left = IsBinaryTreeBST(root->left, bound);
        if (!left) { return false; }
        
        if (bound && bound->val>=root->val) { return false; }
        bound = root;
        auto right = IsBinaryTreeBST(root->right, bound);
        if (!right) { return false; }
        
        return true;
    }
};