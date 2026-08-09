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
        int maxValue = INT_MIN;
        CountGoodNodes(root, maxValue, results);

        return results;
    }

    void CountGoodNodes(TreeNode* root, int maxValue, int& results)
    {
        if (!root) { return; }

        if (maxValue<=root->val) { ++results; }
        if (root->val>maxValue) { maxValue = root->val; }

        CountGoodNodes(root->left, maxValue, results);
        CountGoodNodes(root->right, maxValue, results);
    }
};