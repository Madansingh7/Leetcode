/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // If there are 0 or 1 nodes, nothing to swap
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Dummy node helps handle head changes easily
        ListNode* dummy = new ListNode(0);
        dummy->next =head;

        // prev always points to the node before the current pair
        ListNode* prev =dummy;

        while (prev->next != NULL && prev->next->next != NULL){

            // First and second nodes of the pair
            ListNode* first =prev->next;
            ListNode* second=first->next;

            // Step 1: first points to the node after second
            first->next=second->next;

            // Step 2: second points to first
            second->next =first;

            // Step 3: previous node points to second
            prev->next =second;
            // Move prev to the end of the swapped pair
            prev=first;
        }
        return dummy->next;
    }
};