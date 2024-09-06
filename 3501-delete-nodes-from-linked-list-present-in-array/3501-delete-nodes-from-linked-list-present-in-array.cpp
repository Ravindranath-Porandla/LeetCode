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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        if (st.size() == 0 || head == nullptr)
            return head;

        while (head != nullptr && st.find(head->val) != st.end()) {
            ListNode* del = head;
            head = head->next;
            delete (del);
        }

        ListNode* cur = head->next;
        ListNode* prev = head;

        while (cur != nullptr) {
            int curVal = cur->val;
            if (st.find(curVal) != st.end()) {
                prev->next = cur->next;
                ListNode* del = cur;
                cur = cur->next;
                delete (del);
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};