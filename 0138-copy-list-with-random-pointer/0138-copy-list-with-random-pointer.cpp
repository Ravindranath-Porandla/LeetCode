/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

void insertCopyNodesInBetween(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* copyNode = new Node(temp->val);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
}

void pointRandomNodes(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        Node* copyNode = temp->next;
        if (temp->random) {
            copyNode->random = temp->random->next;
        } else {
            copyNode->random = NULL;
        }
        temp = temp->next->next;
    }
}

Node* getDeepCopyList(Node* head) {
    Node* dummy = new Node(-1);
    Node* temp = head;
    Node* res = dummy;

    while (temp != NULL) {
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }
    return dummy->next;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        insertCopyNodesInBetween(head);
        pointRandomNodes(head);
        return getDeepCopyList(head);
    }
};