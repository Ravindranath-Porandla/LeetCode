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
    bool findPath(TreeNode* root, int target, string& path) {
        if (root == nullptr)
            return false;

        if(root->val == target)
            return true;

        path.push_back('L');
        if (findPath(root->left, target, path) == true)
            return true;
        path.pop_back();
        
        path.push_back('R');
        if (findPath(root->right, target, path) == true)
            return true;
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootTOsrc = "";
        string rootTOdest = "";

        findPath(root, startValue, rootTOsrc);
        findPath(root, destValue, rootTOdest);

        int i = 0;
        int j = 0;

        while (i < rootTOsrc.size() && j < rootTOdest.size() &&
               rootTOsrc[i] == rootTOdest[j]) {
            i++;
            j++;
        }
        string res = "";
        for (; i < rootTOsrc.size(); i++)
            res.push_back('U');

        for (; j < rootTOdest.size(); j++)
            res.push_back(rootTOdest[j]);

        return res;
    }
};