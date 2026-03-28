/*
QUESTION:-
Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
*/

/*
APPROACH:
1. We initialise two listnodes, slow and fast. Fast will jump 2 nodes at a time. Slow will jump to the next node itself.
2. While fast != NULL && fast->next != NULL {since for odd number of nodes, if we reach the last node, fast will jump NULL, and hence reach an unknown pointer}, we jump fast to next to next and slow to the next node.
3. After traversing through the loop, return slow {the middle node of the linked list}.
*/

//CODE:
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
