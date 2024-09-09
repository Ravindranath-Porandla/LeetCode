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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        ListNode* temp = head;

        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = m - 1;

        while (temp != nullptr && left <= right && top <= bottom) {
            for (int col = left; col <= right && temp != nullptr; col++) {
                matrix[top][col] = temp->val;
                temp = temp->next;
            }
            top++;

            for (int row = top; row <= bottom && temp != nullptr; row++) {
                matrix[row][right] = temp->val;
                temp = temp->next;
            }
            right--;

            for (int col = right; col >= left && temp != nullptr; col--) {
                matrix[bottom][col] = temp->val;
                temp = temp->next;
            }
            bottom--;

            for (int row = bottom; row >= top && temp != nullptr; row--) {
                matrix[row][left] = temp->val;
                temp = temp->next;
            }
            left++;
        }
        return matrix;
    }
};