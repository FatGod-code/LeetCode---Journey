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
        int results = 0;
        TreeNode* maxNode = nullptr;
        CountGoodNodes(root, maxNode, results);

        return results;
    }

    void CountGoodNodes(TreeNode* root, TreeNode* maxNode, int& results)
    {
        if (!root) { return; }

        if (!maxNode || maxNode->val<=root->val) { ++results; }
        if (!maxNode || root->val>maxNode->val) { maxNode = root; }

        CountGoodNodes(root->left, maxNode, results);
        CountGoodNodes(root->right, maxNode, results);
    }
};