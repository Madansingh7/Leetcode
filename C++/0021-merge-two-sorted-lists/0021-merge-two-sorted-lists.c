/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* NODE;
NODE mergeTwoLists(NODE l1, NODE l2) {
    NODE temp = (NODE)malloc(sizeof(struct ListNode));
    temp->val = 0;
    temp->next = NULL;
    NODE last=temp;
    while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                last->next= l1;   
                l1 =l1->next;
            }
            else{
                last->next= l2;  
                l2=l2->next;     
            }
            last = last->next;
        }

        if(l1 != NULL) last->next = l1;
        else last->next = l2;

        return temp->next;
}