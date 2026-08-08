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
        auto diameterHeightPair = CountMaxDiameter(root);

        return diameterHeightPair.first;
    }

    std::pair<int, int> CountMaxDiameter(TreeNode* root)
    {
        if (!root) { return {0, 0}; }

        auto left = CountMaxDiameter(root->left);
        auto right = CountMaxDiameter(root->right);

        int diameter = left.second+right.second;

        std::pair<int, int> diameterHeightPair;
        diameterHeightPair.first = std::max(diameter, std::max(left.first, right.first));
        diameterHeightPair.second = std::max(left.second, right.second)+1;

        return diameterHeightPair;
    }
};