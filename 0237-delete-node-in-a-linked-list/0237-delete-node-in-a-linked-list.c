/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* NODE;
void deleteNode(NODE node) {
    int temp;
    node->val=(node->next)->val;
    node->next=(node->next)->next;
}