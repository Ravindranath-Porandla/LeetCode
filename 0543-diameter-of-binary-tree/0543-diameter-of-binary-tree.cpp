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
    int solve(TreeNode* root, int& res) {
        if (root == nullptr)
            return 0;

        int left_height = solve(root->left, res);
        int right_height = solve(root->right, res);

        res = max(res, right_height + left_height);

        return max(left_height, right_height) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        solve(root, res);
        return res;
    }
};