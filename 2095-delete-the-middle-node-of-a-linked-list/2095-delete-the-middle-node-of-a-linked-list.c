/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* NODE;
struct ListNode* deleteMiddle(NODE head) {
    if(head==NULL||head->next==NULL)return NULL;
    NODE curr=head,prev=NULL;
    int count=0;
    while(curr!=NULL){
        curr=curr->next;
        count++;
    }
    int mid = count/2;

    curr=head;
    for(int i=0; i<mid; i++){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    free(curr);
    return head;
}