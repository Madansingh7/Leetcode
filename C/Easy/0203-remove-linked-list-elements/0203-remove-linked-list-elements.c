/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* NODE;

struct ListNode* removeElements(NODE head, int val) {

    while (head != NULL && head->val == val) {
        NODE temp = head;
        head = head->next;
        free(temp);
    }

    if (head == NULL) return NULL;

    NODE curr = head;
    NODE prev = NULL;

    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}
