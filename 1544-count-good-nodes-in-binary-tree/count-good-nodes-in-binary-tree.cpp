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
    int goodNodes(TreeNode* root)
    {
        return CountGoodNodes(root, nullptr);;
    }

    int CountGoodNodes(TreeNode* root, TreeNode* maxNode)
    {
        if (!root) { return 0; }

        int isGoodNode = 0;
        if (!maxNode || root->val>=maxNode->val)
        {
            isGoodNode = 1;
            maxNode = root;
        }

        auto left = CountGoodNodes(root->left, maxNode);
        auto right = CountGoodNodes(root->right, maxNode);

        return left+right+isGoodNode;
    }
};