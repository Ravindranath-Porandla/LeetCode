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
    void solve(TreeNode* root, int targetSum, vector<int>& ds,
               vector<vector<int>>& ans) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr &&
            targetSum == root->val) {
            ds.push_back(root->val);
            ans.push_back(ds);
            ds.pop_back();
            return;
        }
        ds.push_back(root->val);
        solve(root->left, targetSum - root->val, ds, ans);
        solve(root->right, targetSum - root->val, ds, ans);
        ds.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(root, targetSum, ds, ans);
        return ans;
    }
};