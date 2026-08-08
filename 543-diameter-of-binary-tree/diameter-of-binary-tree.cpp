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
    int diameterOfBinaryTree(TreeNode* root)
    {
        int maxDiameter = 0;
        (void) CountMaxDiameter(root, maxDiameter);

        return maxDiameter;
    }

    int CountMaxDiameter(TreeNode* root, int& maxDiameter)
    {
        if (!root) { return 0; }

        auto left = CountMaxDiameter(root->left, maxDiameter);
        auto right = CountMaxDiameter(root->right, maxDiameter);

        int diameter = left+right;
        maxDiameter = std::max(diameter, maxDiameter);

        return std::max(left, right)+1;
    }
};