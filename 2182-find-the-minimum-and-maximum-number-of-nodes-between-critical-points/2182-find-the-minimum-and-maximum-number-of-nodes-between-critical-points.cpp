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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return {-1, -1};
        }

        vector<int> criticalPoints;
        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* nex = head->next->next;
        int index = 1;

        while (nex != nullptr) {
            if ((cur->val > prev->val && cur->val > nex->val) ||
                (cur->val < prev->val && cur->val < nex->val)) {
                criticalPoints.push_back(index);
            }
            prev = cur;
            cur = nex;
            nex = nex->next;
            index++;
        }

        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }

        int minDistance = INT_MAX;
        for (int i = 1; i < criticalPoints.size(); i++) {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }

        int maxDistance = criticalPoints.back() - criticalPoints.front();

        return {minDistance, maxDistance};
    }
};
