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
    bool isMirror(TreeNode* root_left, TreeNode* root_right) {
        if (root_left == nullptr && root_right == nullptr) {
            return true;
        }
        if (root_left == nullptr || root_right == nullptr) {
            return false;
        }
        if (root_left->val != root_right->val) {
            return false;
        }
        return isMirror(root_left->left, root_right->right) &&
               isMirror(root_left->right, root_right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return false;
        return isMirror(root->left, root->right);
    }
};