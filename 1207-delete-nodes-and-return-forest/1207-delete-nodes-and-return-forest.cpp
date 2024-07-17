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
    TreeNode* solve(TreeNode* root, vector<TreeNode*>& ans,
                    unordered_set<int>& st) {
        if (root == nullptr)
            return nullptr;

        root->left = solve(root->left, ans, st);
        root->right = solve(root->right, ans, st);

        if (st.find(root->val) != st.end()) {
            if (root->left != nullptr) {
                ans.push_back(root->left);
                root->left = nullptr;
            }
            if (root->right != nullptr) {
                ans.push_back(root->right);
                root->right = nullptr;
            }
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st;
        for (int node : to_delete) {
            st.insert(node);
        }
        if (st.find(root->val) == st.end())
            ans.push_back(root);
        solve(root, ans, st);
        return ans;
    }
};