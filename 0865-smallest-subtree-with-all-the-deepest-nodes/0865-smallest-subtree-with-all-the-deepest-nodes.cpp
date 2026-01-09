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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }

    pair<int,TreeNode*> dfs(TreeNode* node){
        if(!node) return {0, nullptr};

        // Check for height of left and right subtree
        pair<int, TreeNode*> left = dfs(node->left);
        pair<int, TreeNode*> right = dfs(node->right);

        // If left and right's height are same, it means deepest nodes are split among both sides.
        if(left.first == right.first){
            return {left.first + 1, node};
        }
        // If left's height is more, we have our answer on the left side.
        else if(left.first > right.first){
            return {left.first + 1, left.second};
        }
        // If right's height is more, we have our answer on the right side.
        else{
            return {right.first + 1, right.second};
        }
        
    }
};