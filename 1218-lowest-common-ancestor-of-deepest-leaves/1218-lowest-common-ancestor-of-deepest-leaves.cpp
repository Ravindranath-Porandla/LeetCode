/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int findDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = 1 + findDepth(root->left);
        int right = 1 + findDepth(root->right);

        return max(left, right);
    }
    TreeNode* solve(TreeNode* root, int d, int depth) {
        if(root == nullptr)
            return nullptr;
        if (depth == d)
            return root;

        TreeNode* left = solve(root->left, d + 1, depth);
        TreeNode* right = solve(root->right, d + 1, depth);

        if (left != nullptr && right != nullptr)
            return root;
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        return nullptr;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int depth = findDepth(root);
        return solve(root, 1, depth);
    }
};