/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* NODE;
NODE deleteDuplicates(NODE head) {
    if(head == NULL)return head;
    NODE prev=head;
    NODE curr=head->next;

    while(curr!=NULL){
        if(curr->val == prev->val){
            prev->next=curr->next;
            free(curr);
            curr=prev->next;
        }
        else{
            prev=curr;
            curr=curr->next;
        }
        
    }
    return head;
}