/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode* NODE;
int getDecimalValue(NODE head) {
    NODE curr=head,f=head;
    int n=0;
    while(curr->next!=NULL){
        curr=curr->next;
        n++;
    }
    int res=0;
    while(f!=NULL){
        res=res+(pow(2,n) * f->val);
        n--;
        f=f->next;
    }
return res;
}