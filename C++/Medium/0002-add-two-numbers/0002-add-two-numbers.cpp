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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // Carry for addition
        int carry = 0;

        // Dummy node to simplify answer creation
        ListNode* dummy = new ListNode(0);

        // Points to the last node of the answer list
        ListNode* current = dummy;

        // Continue until both lists and carry are finished
        while (l1 != NULL || l2 != NULL || carry != 0) {

            // Start with previous carry
            int sum = carry;

            // Add current value from first list
            if (l1 != NULL) {
                sum = sum + l1->val;
                l1 = l1->next;
            }

            // Add current value from second list
            if (l2 != NULL) {
                sum = sum + l2->val;
                l2 = l2->next;
            }

            // Calculate carry for the next iteration
            carry = sum / 10;

            // Find the digit to store
            int digit = sum % 10;

            // Create a node with that digit
            ListNode* newNode = new ListNode(digit);

            // Attach it to the answer list
            current->next = newNode;

            // Move current to the newly added node
            current = current->next;
        }

        // Skip the dummy node and return the real answer
        return dummy->next;
    }
};