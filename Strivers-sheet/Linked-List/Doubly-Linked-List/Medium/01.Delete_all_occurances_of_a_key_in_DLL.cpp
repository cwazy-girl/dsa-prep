/*
QUESTION:-
Given the head of a doubly linked list and an integer target. Delete all nodes in the linked list with the value target and return the head of the modified linked list.

Example:

Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1
Output: head -> 2 <-> 3 <-> 4
Explanation: All nodes with the value 1 were removed.
*/

/*
APPROACH:
1. We initialise a move pointer, with the node value of head.
2. We first create conditions for deletio of head pointer. So, while move != NULL {to prevent doing anything if linked list becomes empty} and move->val == target, we save head value in a temp node.
3. We move head to head->next, and then check if head is NULL. If not, we point head->prev to NULL.
4. Now, we delete temp, and assign move back to head.
5. Now for occurances other than head, while move && move->next != NULL, we see if the next node value of move is equal to target.
6. If yes, we save the next node in temp. We shift move->next to move->next->next.
7. If move->next is not NULL, we assign it's prev value to move. Now, delete temp.
8. If not, we shift move to move->next.
9. Return head.
*/

//CODE:
class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        ListNode* move = head;

        while(move != NULL && move->val == target) {
            ListNode* temp = head;
            head = head->next;
            if(head) head->prev = NULL;
            delete temp;
            move = head;
        }

        while(move && move->next) {
            if(move->next->val == target) {
                ListNode* temp = move->next;
                move->next = move->next->next;
                if(move->next)move->next->prev = move;
                delete temp;
            }
            else {
                move = move->next;
            }
        }
        return head;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
