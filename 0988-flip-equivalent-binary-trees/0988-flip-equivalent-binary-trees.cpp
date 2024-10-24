class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return true; // Both are null, so they are equivalent
        if (root1 == nullptr || root2 == nullptr)
            return false; // One is null, the other isn't, not equivalent
        if (root1->val != root2->val)
            return false; // The values don't match, not equivalent

        // Check both flipped and non-flipped conditions
        return (flipEquiv(root1->left, root2->left) &&
                flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) &&
                flipEquiv(root1->right, root2->left));
    }
};
