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
    TreeNode* convertToBBST(int left, int right, vector<int>& arr){
        if(left > right)    return nullptr;
        
        int mid = (right + left) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = convertToBBST(left, mid - 1, arr);
        root->right = convertToBBST(mid + 1, right, arr);
        
        return root;
    }
    void inorder(TreeNode* root, vector<int>& arr){
        if(root == nullptr)    return;
        
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root)   return root;
        vector<int> arr;
        inorder(root, arr);
        int left = 0;
        int right = arr.size() - 1;
        TreeNode* ans = convertToBBST(left, right, arr);
        return ans;
    }
};