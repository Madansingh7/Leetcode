/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* NODE;

struct ListNode* middleNode(NODE head) {
    if (head == NULL || head->next == NULL)
        return head;

    //Count nodes
    int count = 0;
    NODE curr = head;

    while (curr != NULL) {
        count++;
        curr = curr->next;
    }

    //find middle index
    int mid = count / 2;   // Works for both even & odd

    //Move to middle node
    curr = head;
    for (int i = 0; i < mid; i++) {
        curr = curr->next;
    }

    return curr;
}