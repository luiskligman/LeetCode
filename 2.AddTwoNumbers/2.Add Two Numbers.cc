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
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {  // continue as long as any of these
                                                          // statements are true
            int x = l1 ? l1->val : 0;  // checks if l1 is NULLPTR,
                                       // IF not then x = val of l1, ELSE x = 0
            // if (l1)  means if (l1 != NULLPTR)
            // if (!l1)  means if (l1 == NULLPTR)
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;  // integer division
            curr->next = new ListNode(sum % 10);  // creates new node that holds sum % 10
            curr = curr->next;  // update the linked list, move curr one forward
            l1 = l1 ? l1->next : nullptr;  // advance l1 to next node in linked list, else, set to NULLPTR
            l2 = l2 ? l2->next : nullptr;  // advance l2 to next node in linked list, else, set to NULLPTR
        }
        ListNode* result = dummyHead->next;  // set first result pointer to the first real element
                                             // in the linked list we used
        delete dummyHead;  // dummyHead was used as a tool to help us build the linked list,
                           // it is no longer needed so we need to free the memory allocated for it
        return result;
    }
};