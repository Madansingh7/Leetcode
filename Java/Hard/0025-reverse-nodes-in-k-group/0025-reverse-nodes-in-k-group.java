class Solution {

    public int len(ListNode head) {
        int cnt = 0;

        while (head != null) {
            cnt++;
            head = head.next;
        }

        return cnt;
    }

    public ListNode reverseKGroup(ListNode head, int k) {

        int Len = len(head);
        int groups = Len / k;

        ListNode prevHead = null;
        ListNode curHead = head;
        ListNode ansNode = null;

        for (int i = 0; i < groups; i++) {

            ListNode prev = null;
            ListNode cur = curHead;
            ListNode nextNode = null;

            // Reverse k nodes
            for (int j = 0; j < k; j++) {

                nextNode = cur.next;
                cur.next = prev;
                prev = cur;
                cur = nextNode;
            }

            // Connect previous group to current reversed group
            if (prevHead == null) {
                ansNode = prev;
            } 
            else {
                prevHead.next = prev;
            }

            // curHead is now the last node of reversed group
            prevHead = curHead;

            // cur is the first node of next group
            curHead = cur;
        }

        // Connect last reversed group to remaining nodes
        prevHead.next = curHead;

        return ansNode;
    }
}