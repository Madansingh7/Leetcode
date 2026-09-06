/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode* NODE;

NODE rotateRight(NODE head, int k) {

    if(head == NULL || head->next == NULL || k == 0)
        return head;

    //stp1 - find length and tail
    int n = 1;
    NODE tail = head;

    while(tail->next != NULL){
        tail = tail->next;
        n++;
    }

    //reduce rotations
    k = k % n;
    if(k == 0) return head;

    //make circular
    tail->next = head;

    //find new tail

    NODE newTail = head;

    for(int i = 0; i < n-k-1; i++){
        newTail = newTail->next;
    }

    //set new head
    NODE newHead = newTail->next;

    //break circle
    newTail->next = NULL;

    return newHead;
}