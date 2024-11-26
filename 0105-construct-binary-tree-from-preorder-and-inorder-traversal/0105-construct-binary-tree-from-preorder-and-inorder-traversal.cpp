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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = build(preorder, 0, n - 1, inorder, 0, n - 1, mp);
        return root;
    }
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd,
    unordered_map<int, int>& mp){
        if(preStart > preEnd || inStart > inEnd)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int idx = mp[root->val];
        int lenLeft = idx - inStart;

        root->left = build(preorder, preStart + 1, preStart + lenLeft, inorder, inStart, idx - 1, mp);
        root->right = build(preorder, preStart + lenLeft + 1, preEnd, inorder, idx + 1, inEnd, mp);

        return root;
    }
};