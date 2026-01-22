/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* NODE;

NODE deleteDuplicates(NODE head) {
    if (head == NULL) return NULL;

    struct ListNode temp;
    temp.next = head;

    NODE prev = &temp;
    NODE curr = head;

    while (curr != NULL) {
        // detect duplicates
        if (curr->next!=NULL && curr->val == curr->next->val) {

            int temp = curr->val;
            while (curr != NULL && curr->val == temp) {
                curr =curr->next;
            }

            prev->next = curr;   // unlink all duplicates
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return temp.next;
}