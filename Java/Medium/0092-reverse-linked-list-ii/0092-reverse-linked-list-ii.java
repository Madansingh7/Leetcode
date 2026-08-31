/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {

        if (head == null || left == right) {
            return head;
        }

        ListNode dummy = new ListNode(0);
        dummy.next = head;

        // Reach the node before 'left'
        ListNode beforeLeft = dummy;

        for (int i = 1; i < left; i++) {
            beforeLeft = beforeLeft.next;
        }

        // Start reversing
        ListNode prev = null;
        ListNode curr = beforeLeft.next;

        for (int i = 0; i <= right - left; i++) {
            ListNode next = curr.next;

            curr.next = prev;
            prev = curr;
            curr = next;
        }

        // Connect the reversed part
        beforeLeft.next.next = curr;
        beforeLeft.next = prev;

        return dummy.next;
    }
}