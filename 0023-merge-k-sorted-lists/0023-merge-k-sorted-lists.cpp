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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size())
            return nullptr;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;

        int k = lists.size();
        for (int i = 0; i < k; i++) {
            if (lists[i])
                pq.push({lists[i]->val, lists[i]});
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (!pq.empty()) {
            pair<int, ListNode*> p = pq.top();
            temp->next = p.second;
            pq.pop();
            if (p.second->next) {
                pq.push({p.second->next->val, p.second->next});
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};