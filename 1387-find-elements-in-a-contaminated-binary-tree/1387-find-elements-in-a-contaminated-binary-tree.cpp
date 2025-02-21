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
class FindElements {
private:
    TreeNode* root;  // ✅ Store root as a member variable

    void construct(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            root->left->val = root->val * 2 + 1;
            construct(root->left);
        }
        if (root->right) {
            root->right->val = root->val * 2 + 2;
            construct(root->right);
        }
    }

    bool findTarget(TreeNode* node, int target) {
        if (!node) {
            return false;
        }

        if (node->val == target) {
            return true;
        }

        return findTarget(node->left, target) || findTarget(node->right, target);
    }

public:
    FindElements(TreeNode* root) {
        this->root = root;  // ✅ Store the root
        if (root) {
            root->val = 0;
            construct(root);
        }
    }

    bool find(int target) {
        return findTarget(root, target);  // ✅ Use stored root
    }
};
