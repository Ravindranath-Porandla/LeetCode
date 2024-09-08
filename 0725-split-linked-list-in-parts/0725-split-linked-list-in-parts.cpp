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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            len++;
        }
        int x = len / k;
        int y = len % k;
        ListNode* cur = head;

        vector<ListNode*> ans(k, nullptr);
        for (int i = 0; i < k; i++) {
            int list_len = x;
            if (y > 0) {
                list_len++;
                y--;
            }
            if (list_len == 0) {
                ans[i] = nullptr;
            } else {
                ans[i] = cur;
                ListNode* prev = nullptr;
                while (list_len--) {
                    prev = cur;
                    cur = cur->next;
                }
                prev->next = nullptr;
            }
        }
        return ans;
    }
};