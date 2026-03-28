/*
QUESTION:-
Given the head of a doubly linked list and an integer X, insert a node with value X before the head of the linked list and return the head of the modified list.

Example:

Input: head = [1, 2, 3], X = 3
Output: head = [3, 1, 2, 3]
Explanation: 3 was added before the 1st node. Note that the head's value is changed.
*/

/*
APPROACH:
1. Assign value X to a new listnode named {newnode}.
2. If head == NULL, we return newnode.
3. We point next pointer of newnode to head, and the prev pointer of head to newnode.
4. Return newnode.
*/

//CODE:
class Solution {
public:
    ListNode* insertBeforeHead(ListNode* head, int X) {
        ListNode* newnode = new ListNode(X);

        if (head == NULL) {
            return newnode;
        }

        newnode->next = head;
        head->prev = newnode;
        return newnode;
    }
};

//Time Complexity : O(1)
//Space Complexity : O(1)
