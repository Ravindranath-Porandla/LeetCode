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
    TreeNode* solve(int& i, string& traversal, int n, int depth) {
        if (i >= n) return nullptr;

        // Count number of dashes to determine depth
        int j = i;
        while (j < n && traversal[j] == '-') {
            j++;
        }
        int dashCount = j - i;
        if (dashCount != depth) {
            return nullptr;
        }
        i = j;  // Move i past the dashes

        // Extract the numeric value
        int num = 0;
        while (i < n && isdigit(traversal[i])) {
            num = num * 10 + (traversal[i] - '0');
            i++;
        }

        TreeNode* root = new TreeNode(num);

        root->left = solve(i, traversal, n, depth + 1);
        root->right = solve(i, traversal, n, depth + 1);

        return root;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int i = 0;
        return solve(i, traversal, n, 0);
    }
};
