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
    int maxPathSum(TreeNode* root)
    {
        int maxPathSum = INT_MIN;
        (void) CountMaxPathSum(root, maxPathSum);

        return maxPathSum;
    }

    int CountMaxPathSum(TreeNode* root, int& maxPathSum)
    {
        if (!root) { return 0; }

        auto left = std::max(0, CountMaxPathSum(root->left, maxPathSum));
        auto right = std::max(0, CountMaxPathSum(root->right, maxPathSum));

        int pathSum = root->val+left+right;
        maxPathSum = std::max(pathSum, maxPathSum);

        return std::max(root->val+left, root->val+right);
    }
};