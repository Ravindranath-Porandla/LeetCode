/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if (start > end)
            return nullptr;

        int mid = (start + (end - start) / 2);
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(nums, start, mid - 1);
        node->right = helper(nums, mid + 1, end);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp = head;
        vector<int> nums;
        while (temp != nullptr) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        int n = nums.size();
        TreeNode* root = helper(nums, 0, n - 1);
        return root;
    }
};