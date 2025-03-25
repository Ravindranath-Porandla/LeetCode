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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
            return nullptr;
        while (head != nullptr && head->val == val) {
            ListNode* todel = head;
            head = head->next;
            delete todel;
        }
        ListNode* temp = head;
        if(temp == nullptr) return NULL;
        while (temp->next != nullptr) {
            if (temp->next->val == val) {
                ListNode* todel = temp->next;
                temp->next = temp->next->next;
                delete todel;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};