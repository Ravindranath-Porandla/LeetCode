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
    TreeNode* deleteHelper(TreeNode* root, unordered_set<int>& st,
                           vector<TreeNode*>& ans) {
        if (root == nullptr)
            return nullptr;

        root -> left = deleteHelper(root->left, st, ans);
        root -> right = deleteHelper(root->right, st, ans);

        if (st.find(root->val) != st.end()) {
            if (root->left != nullptr)
                ans.push_back(root->left);
            if (root->right != nullptr)
                ans.push_back(root->right);

            return nullptr;
        } else {
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;

        unordered_set<int> st;

        for (auto i : to_delete) {
            st.insert(i);
        }

        deleteHelper(root, st, ans);

        if (st.find(root->val) == st.end()) {
            ans.push_back(root);
        }
        return ans;
    }
};