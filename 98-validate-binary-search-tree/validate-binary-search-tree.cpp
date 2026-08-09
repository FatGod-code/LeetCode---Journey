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
        TreeNode* prevNode = nullptr;
        return IsBinaryTreeBST(root, prevNode);
    }

    bool IsBinaryTreeBST(TreeNode* root, TreeNode*& prevNode)
    {
        if (!root) { return true; }
        
        if (!IsBinaryTreeBST(root->left, prevNode)) { return false; }
        
        if (prevNode && prevNode->val>=root->val) { return false; }
        prevNode = root;
        
        if (!IsBinaryTreeBST(root->right, prevNode)) { return false; }
        
        return true;
    }
};