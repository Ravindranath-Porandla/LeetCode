/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

// 1 1 1 2 3 5 1 null
// target = 1
//
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if (head == null)
            return null;
        ListNode temp = head;

        while (temp != null && temp.val == val)
            temp = temp.next;

        head = temp;
        if(head == null)    return null;

        while (temp.next != null) {
            if (temp.next.val == val) {
                temp.next = temp.next.next;
            } else {
                temp = temp.next;
            }
        }

        return head;
    }
}