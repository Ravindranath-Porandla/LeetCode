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
    long long int totalSum;
    long long int maxPro;
    long long int findSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        long long int left = findSum(root->left);
        long long int right = findSum(root->right);
        long long int subTreeSum = left + right + root->val;

        maxPro = max(maxPro, (totalSum - subTreeSum) * subTreeSum);

        return subTreeSum;
    }
    int maxProduct(TreeNode* root) { 
        maxPro = INT_MIN;
        totalSum = findSum(root);
        long long int sum = findSum(root);

        return maxPro % (int)(1e9 + 7);
    }
};