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
    string solve(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& ans) {
        if (root == nullptr) {
            return "N";  // Using "N" to represent null node in serialization
        }

        string str = to_string(root->val) + "," + solve(root->left, mp, ans) +
                     "," + solve(root->right, mp, ans);

        if (mp[str] == 1) {
            ans.push_back(root);  // If subtree string is already in set, it's a duplicate
        }

        mp[str]++;  // Insert current subtree string into set

        return str;  // Return the serialized string representation of the subtree
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> ans;

        solve(root, mp, ans);  // Call the recursive function to find duplicates

        return ans;  // Return the list of duplicate subtrees
    }
};
