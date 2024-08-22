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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode* dummy = new ListNode(-1);
        ListNode* newHead = dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while ((temp1 != nullptr) && (temp2 != nullptr)) {
            if (temp1->val > temp2->val) {
                dummy->next = temp2;
                temp2 = temp2->next;
            } else {
                dummy->next = temp1;
                temp1 = temp1->next;
            }
            dummy = dummy->next;
        }

        while (temp1 != nullptr) {
            dummy->next = temp1;
            temp1 = temp1->next;
            dummy = dummy->next;
        }

        while (temp2 != nullptr) {
            dummy->next = temp2;
            temp2 = temp2->next;
            dummy = dummy->next;
        }

        return newHead->next;
    }
};