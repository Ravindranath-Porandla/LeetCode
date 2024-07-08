class Solution {
public:
    TreeNode* construct(int& idx, int start, int end, vector<int>& inorder,
                        vector<int>& postorder) {
        if (start > end) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[idx]);
        // Find the index of root->val in inorder array
        int i = start;
        while (i <= end && inorder[i] != root->val) {
            i++;
        }

        // Update idx for next recursive calls
        idx--;

        // Build right subtree first (postorder traversal)
        root->right = construct(idx, i + 1, end, inorder, postorder);
        // Build left subtree (postorder traversal)
        root->left = construct(idx, start, i - 1, inorder, postorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        // Start with the last element in postorder as root
        int idx = n - 1;
        TreeNode* root = construct(idx, 0, n - 1, inorder, postorder);
        return root;
    }
};
