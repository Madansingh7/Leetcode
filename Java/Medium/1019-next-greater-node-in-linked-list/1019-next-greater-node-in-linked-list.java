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
    public int[] nextLargerNodes(ListNode head) {

        // Convert linked list to array
        List<Integer> nums = new ArrayList<>();

        while (head != null) {
            nums.add(head.val);
            head = head.next;
        }

        int n = nums.size();

        int[] ans = new int[n];

        // Stack stores indices
        Deque<Integer> stack = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {

            while (!stack.isEmpty() &&
                   nums.get(i) > nums.get(stack.peek())) {

                int index = stack.pop();

                ans[index] = nums.get(i);
            }

            stack.push(i);
        }

        return ans;
    }
}