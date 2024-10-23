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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr)
            return root;

        queue<TreeNode*> q;
        q.push(root);
        vector<int> levelSum;

        while (!q.empty()) {
            int curSum = 0;
            int n = q.size();

            while (n--) {
                auto front = q.front();
                q.pop();
                curSum += front->val;
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            levelSum.push_back(curSum);
        }

        q.push(root);
        root->val = 0;
        int i = 1;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto front = q.front();
                q.pop();
                int siblingSum = front->left != NULL ? front->left->val : 0;
                siblingSum += front->right != NULL ? front->right->val : 0;

                if (front->left) {
                    front->left->val = levelSum[i] - siblingSum;
                    q.push(front->left);
                }
                if (front->right) {
                    front->right->val = levelSum[i] - siblingSum;
                    q.push(front->right);
                }
            }
            i++;
        }
        return root;
    }
};