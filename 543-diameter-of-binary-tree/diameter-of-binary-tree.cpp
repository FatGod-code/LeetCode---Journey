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
        auto diameterHeightPair = CountMaxDiameter(root);
        return diameterHeightPair.first;
    }

    std::pair<int, int> CountMaxDiameter(TreeNode* root)
    {
        if (!root) { return {0, 0}; }

        auto [leftDiameter, leftHeight] = CountMaxDiameter(root->left);
        auto [rightDiameter, rightHeight] = CountMaxDiameter(root->right);

        int diameter = leftHeight+rightHeight;

        int maxDiameter = std::max({diameter, leftDiameter, rightDiameter});
        int maxHeight = std::max(leftHeight, rightHeight)+1;

        return {maxDiameter, maxHeight};
    }
};