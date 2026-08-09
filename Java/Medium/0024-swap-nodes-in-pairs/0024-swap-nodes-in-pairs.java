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
    public ListNode swapPairs(ListNode head) {

        // If there are 0 or 1 nodes, nothing to swap
        if (head == null || head.next == null) {
            return head;
        }

        // Dummy node helps handle head changes easily
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        // prev always points to the node before the current pair
        ListNode prev = dummy;

        while (prev.next != null && prev.next.next != null) {

            // First and second nodes of the pair
            ListNode first = prev.next;
            ListNode second = first.next;

            // Step 1: first points to the node after second
            first.next = second.next;

            // Step 2: second points to first
            second.next = first;

            // Step 3: previous node points to second
            prev.next = second;

            // Move prev to the end of the swapped pair
            prev = first;
        }

        return dummy.next;
    }
}